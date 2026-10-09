/*Write a C program using fork() in which the parent prints even numbers from 2 to 20 and
 the child prints odd numbers from 1 to 19.*/

 /*Write a C program that accepts the number of Fibonacci terms and a number for factorial calculation, then uses fork() so that
 the child prints the Fibonacci series and the parent calculates and prints the factorial.*/

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
       for(int i=1;i<=19;i++){
          if(i%2!=0){
            printf("%d ",i);
          }
       }
       printf("\n");
    }
    else{ //Parent Process
        wait(NULL);
       printf("Parent Process running!\n");
       for(int i=0;i<=20;i++){
          if(i%2==0){
            printf("%d ",i);
          }
       }
       printf("\n");
    }
    return 0;
}