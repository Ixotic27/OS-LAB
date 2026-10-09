/*Write a C program to demonstrate a zombie process by allowing the child to terminate
while the parent remains alive and does not immediately call wait().*/

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
    else if (pid == 0) //Child process becomes a zombie as its status is not collected by the parent process
    {
        printf("Child process!\n");
        printf("Child PID = %d & Parent PID = %d\n", getpid(), getppid());
        return 0;
    }
    else
    {
        printf("Parent Process!\n");
        sleep(10);
        printf("Parent process exiting!\n");
        return 0;
    }
    return 0;
}