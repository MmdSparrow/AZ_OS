#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

#define WRITE_END 1
#define READ_END 0
#define LENGTH 50

char default_message[] = "This Is First Process";

void convertStr(char in[LENGTH]);

void writer(int pipefd[2], char message[LENGTH]);
void reader(int pipefd[2], char message[LENGTH]);

int main() {
    int pipefd1[2];
    int pipefd2[2];
    int pid;


    int pipe1_status = pipe(pipefd1);
    int pipe2_status = pipe(pipefd2);

    if (pipe1_status < 0 || pipe2_status <0) {
        perror("error!");
        exit(-1);
    }

    printf("default message: %s\n", default_message);
    writer(pipefd1, default_message);

    char inputMessage[LENGTH];

    if ((pid = fork()) == 0) {
        printf("child process change lower and upper case to each other!\n");
        reader(pipefd1, inputMessage);
        convertStr(inputMessage);
        writer(pipefd2, inputMessage);
    } else{
        wait(NULL);
        printf("father process:\n");
        reader(pipefd2, default_message);
        printf("%s\n", default_message);
    }


    return 0;
}

void writer(int pipefd[2], char message[LENGTH]) {
    write(pipefd[WRITE_END], message, LENGTH);
    close(pipefd[WRITE_END]);
}

void reader(int pipefd[2], char message[LENGTH]) {
    read(pipefd[READ_END], message, LENGTH);
    close(pipefd[READ_END]);
}

void convertStr(char in[LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        if (isupper(in[i]))
            in[i] = tolower(in[i]);
        else
            in[i] = toupper(in[i]);
    }
}