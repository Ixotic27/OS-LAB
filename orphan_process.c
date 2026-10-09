/*Write a C program to demonstrate an orphan process by terminating the parent while the
 child continues execution. Display the child's parent process ID before and after the
 parent terminates.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed!\n");
        return 0;
    }
    else if (pid == 0)
    {
        printf("Child process!\n");
        printf("Child PID = %d & Parent PID = %d\n", getpid(),getppid());
        sleep(3);

        printf("Child PID = %d\n & Parent PID = %d\n", getpid(),getppid());
        printf("Child process exiting!\n");
    }
    else
    {
        printf("Parent Process!\n");
        printf("Parent process exiting!\n");
        return 0;
    }
    return 0;
}