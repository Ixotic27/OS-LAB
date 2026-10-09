/*Write a C program in which the parent calculates the sum of a fixed array, sends the sum 
to the child through a pipe, and the child checks and displays whether the received sum is 
prime.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);
    
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int ar[n];
    printf("Enter the numbers in the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }

    int pid = fork();

    if(pid < 0 ){
        printf("Process creation failed!\n");
        return 0;
    }
    else if( pid == 0){
        close(fd[1]);
        int sum = 0;
        read(fd[0],&sum,sizeof(sum));
        close(fd[0]);

        int prime = 1;
        if(sum<2) prime =0;
        else{
            for(int i=2;i*i<=sum;i++){
                if(sum%i==0){
                    prime = 0;
                    break;
                }
            }
        }
        if(prime) printf("Prime number!\n");
        else printf("Not a prime number!\n");
    }
    else { //Parent Process;
        close(fd[0]);
 
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=ar[i];
        }
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    return 0;
}