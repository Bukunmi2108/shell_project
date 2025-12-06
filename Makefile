CC = gcc
CFLAGS = -Wall -Wextra -g

OBJS = main.o parser.o execute.o art.o chat.o
TARGET = myshell

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lreadline

main.o: main.c shell.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c shell.h
	$(CC) $(CFLAGS) -c parser.c

execute.o: execute.c shell.h
	$(CC) $(CFLAGS) -c execute.c

art.o: art.c
	$(CC) $(CFLAGS) -c art.c

chat.o: chat.c shell.h
	$(CC) $(CFLAGS) -c chat.c

clean:
	rm -f $(OBJS) $(TARGET)

install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)
