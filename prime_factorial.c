/*Write a C program that accepts an integer and uses fork() so that the child checks 
whether the number is prime, while the parent calculates and displays its factorial after 
waiting for the child.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Enter the number: ");
    int n;
    scanf("%d",&n);
    int pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed!\n");
        return 0;
    }
    else if (pid == 0)
    {
        printf("Child process!\n");
        
        int prime = 1;
        if(n<2){
            prime = 0;
        }
        else{
            for(int i=2;i*i <=n;i++){
                if(n%i ==0){
                    prime =0;
                    break;
                }
            }
        }
        if(prime ==1 ){
            printf("Prime number!\n");
        }
        else{
            printf("Not a prime number!\n");
        }
    }
    else
    {
        wait(NULL);
        printf("Parent Process!\n");
        int fact = 1;
        for(int i=2;i<=n;i++){
            fact*=i;
        }
        printf("Factorial: %d\n",fact);
    }
    return 0;
}