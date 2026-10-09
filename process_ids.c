/*Write a C program using fork() in which both the parent and child processes display their Process ID (PID) and Parent Process 
ID (PPID) using getpid() and getppid().*/

#include<stdio.h>
#include<unistd.h>
int main(){
    int pid = fork();
    
    if(pid<0){
        printf("Process Creation Failed.\n");
        return 0;
    }
    else if(pid==0){ //child process
        printf("Process Id: %d\n",getpid());
        printf("Parent Id: %d\n",getppid());
    }
    else{ //Parent process
        printf("Process Id: %d\n",getpid());
        printf("Parent Id: %d\n",getppid());
    }
    return 0;
}