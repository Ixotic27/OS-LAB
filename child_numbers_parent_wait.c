/*Write a C program in which the child process prints the numbers 1 to 5, while the parent process waits for the child to finish
 using wait() and then prints a completion message.*/

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
        for(int i=0;i<5;i++){
            printf("%d ",i+1);
        }
        printf("\nChild process running!\n");
    }
    else{ //Parent Process
        wait(NULL);
       printf("Parent Process running!\n");
    }
}