/*Write a C program to create three child processes. Each child should print its child number, PID, and PPID. The original
 parent should wait for all three child processes to terminate.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int pid = fork();
        if (pid < 0)
        {
            printf("Process creation failed!\n");
            return 0;
        }
        if (pid == 0)
        {
            printf("Child %d\n", i);
            printf("PID = %d\n", getpid());
            printf("PPID = %d\n", getppid());
            return 0;
        }
    }
        for(int i=0;i<3;i++) // Parent waits for all the children
        {
            wait(NULL);
        }

        printf("Parent Process!\n");
        printf("PID = %d\n", getpid());
        printf("PPID = %d\n", getppid());
        return 0;
}