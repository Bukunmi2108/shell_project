#include "shell.h"
#include <readline/readline.h>
#include <readline/history.h>

#define GEMINI_MODEL "gemini-2.5-flash"

// Function to escape special characters in JSON string
void json_escape(char *dest, const char *src) {
    while (*src) {
        if (*src == '"') {
            *dest++ = '\\';
            *dest++ = '"';
        } else if (*src == '\\') {
            *dest++ = '\\';
            *dest++ = '\\';
        } else if (*src == '\n') {
            *dest++ = '\\';
            *dest++ = 'n';
        } else {
            *dest++ = *src;
        }
        src++;
    }
    *dest = '\0';
}

void call_gemini(char *prompt) {
    char *api_key = getenv("GEMINI_API_KEY");
    if (!api_key) {
        printf("\033[1;31mError: GEMINI_API_KEY environment variable not set.\033[0m\n");
        return;
    }

    char escaped_prompt[4096];
    json_escape(escaped_prompt, prompt);

    char command[8192];
    snprintf(command, sizeof(command),
             "curl -s -H 'Content-Type: application/json' "
             "-d '{\"contents\":[{\"parts\":[{\"text\":\"%s\"}]}]}' "
             "\"https://generativelanguage.googleapis.com/v1beta/models/%s:generateContent?key=%s\"",
             escaped_prompt, GEMINI_MODEL, api_key);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error calling Gemini API.\n");
        return;
    }

    // Read response
    char buffer[8192];
    char response[16384] = "";
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(response, buffer);
    }
    pclose(fp);

    char *text_start = strstr(response, "\"text\": \"");
    if (text_start) {
        text_start += 9; // Skip "text": "
        printf("\033[1;36m(Gemini)\033[0m ");
        
        while (*text_start) {
            if (*text_start == '"' && *(text_start-1) != '\\') break; // End of string
            
            if (*text_start == '\\' && *(text_start+1) == 'n') {
                printf("\n");
                text_start++;
            } else if (*text_start != '\\') {
                printf("%c", *text_start);
            }
            text_start++;
        }
        printf("\n");
    } else {
        printf("Failed to parse response or API error.\nRaw response: %s\n", response);
    }
}

int lsh_chat(char **args) {
    (void)args;
    char *line;
    char *user = getenv("USER");
    if (!user) user = "user";
    char prompt[100];
    snprintf(prompt, sizeof(prompt), "\033[1;35m(%s) > \033[0m", user);
    printf("\033[1;35mEntering AI Chat Mode (Gemini %s). Type 'exit' or 'quit' to leave.\033[0m\n", GEMINI_MODEL);

    while (1) {
        line = readline(prompt);
        
        if (!line) break; // EOF
        
        if (strlen(line) > 0) {
            add_history(line);
        }

        if (strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0) {
            free(line);
            break;
        }

        call_gemini(line);
        free(line);
    }
    
    printf("\033[1;35mExiting AI Chat Mode.\033[0m\n");
    return 1;
}
