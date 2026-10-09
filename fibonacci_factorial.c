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
       int n;
       printf("Enter the number: ");
       scanf("%d",&n);
       
       int a=0,b=1;
       printf("0 1 ");
       for(int i=0;i<n-2;i++){
          int temp = a+b;
          printf("%d ",temp);
          a=b;
          b=temp;
       }
       printf("\n");
    }
    else{ //Parent Process
        wait(NULL);
       printf("Parent Process running!\n");
       int fact = 1;
       int n;
       printf("Enter the number: ");
       scanf("%d",&n);
       if(n<2) printf("1");
       else{
        for(int i=n;i>1;i--){
            fact*=i;
        }
        printf("Factorial of %d is %d\n",n,fact);
       }
    }
    return 0;
}