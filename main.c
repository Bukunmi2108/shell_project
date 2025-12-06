#include "shell.h"

#include <readline/readline.h>
#include <readline/history.h>

char *get_prompt() {
    char *user = getenv("USER");
    char host[1024];
    char cwd[1024];
    static char prompt[4096];

    if (!user) user = "user";
    gethostname(host, sizeof(host));
    if (getcwd(cwd, sizeof(cwd)) == NULL) strcpy(cwd, "unknown");

    // Format: [Green]User@Host[Reset]:[Blue]CWD[Reset]$ 
    snprintf(prompt, sizeof(prompt), "\001\033[1;32m\002%s@%s\001\033[0m\002:\001\033[1;34m\002%s\001\033[0m\002$ ", 
             user, host, cwd);
    return prompt;
}

void loop() {
    char *line;
    char **args;
    int status;

    do {
        line = readline(get_prompt());

        if (line == NULL) {
            // EOF (Ctrl+D)
            printf("\n");
            break;
        }

        if (strlen(line) > 0) {
            add_history(line);
        }

        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}

int main() {
    art();
    loop();
    printf("\nGoodbye!\n");

    return 0;
}