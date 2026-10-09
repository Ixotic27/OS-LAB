/*Write a C program to create a child process using fork() and display separate messages identifying the parent process and
child process*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid = fork();
    if(pid<0){
        printf("Process creation failed\n");
        return 0;
    }
    else if(pid == 0){ //Child Process
       printf("Child Process running!\n");
    }
    else{ //Parent Process
        wait(NULL);
       printf("Parent Process running!\n");
    }
}