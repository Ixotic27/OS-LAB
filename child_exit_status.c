/*Write a C program in which the child process terminates with exit status 10, and the 
parent uses wait(), WIFEXITED(), and WEXITSTATUS() to read and display the child's exit
status.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid = fork();

    if(pid<0){
        printf("Process creation failed!\n");
        return 0;
    }
    else if(pid == 0){
        printf("Child process\n");
        exit(10);
    }
    else{
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("Exit status: %d\n",WEXITSTATUS(status));
        }
    }
    return 0;
}