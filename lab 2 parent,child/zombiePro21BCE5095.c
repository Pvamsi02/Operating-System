#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;

    // Fork a new child process
    child_pid = fork();

    if (child_pid == 0) {
        // This is the child process
        printf("I am the child process. My PID is %d.\n", getpid());

        // Terminate the child process
        exit(0);
    } else {
        // This is the parent process
        printf("I am the parent process. My PID is %d.\n", getpid());
        printf("I created a child process with PID %d.\n", child_pid);

        // Sleep for 60 seconds to allow the child process to become a zombie
        sleep(60);
    }

    return 0;
}

