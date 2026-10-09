// Orphan process but using pipe

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);

    int pid = fork();

    if(pid < 0 ){
        printf("Process creation failed!\n");
        return 0;
    }
    else if( pid == 0){
        close(fd[0]); //Closing read

        printf("Child Process!\n");
        printf("Child PID = %d & Parent PID = %d\n", getpid(),getppid());
        
        char c = 'x';
        write(fd[1],&c,sizeof(c)); //writing
        close(fd[1]); //closing write

        sleep(3);
        printf("Child PID = %d & Parent PID = %d\n", getpid(),getppid());
        return 0;
    }
    else {
        close(fd[1]);
        char c;
        read(fd[0],&c,sizeof(c));
        close(fd[0]);
        printf("Parent process exiting now!\n");
    }
}