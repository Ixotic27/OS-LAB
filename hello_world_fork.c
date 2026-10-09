//Write a C program to create a child process using fork() and print "Hello World" from both the parent and child processes.

#include<stdio.h>
#include<unistd.h>
int main(){
    int x = fork();
    printf("Hello World\n");
}