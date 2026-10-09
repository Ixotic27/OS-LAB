/*Write a C program in which the parent creates input.txt, writes a name, university roll number, and class into it, and the
child opens the file, reads its contents, and displays them.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>

int main()
{
    int fd[2];
    pipe(fd);
    int pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed!\n");
        return 0;
    }
    else if (pid == 0)
    {
        close(fd[1]);
        char file_name[100];
        int n = read(fd[0],file_name,sizeof(file_name)-1);
        file_name[n] = '\0';
        close(fd[0]);

         FILE * f;
         f= fopen(file_name,"r");

         if (f == NULL)
        {
            printf("File could not be opened!\n");
            return 1;
        }
         
         char str[100];
         while(fgets(str,sizeof(str),f) != NULL)
         {
             printf("%s",str);
         }
         fclose(f);
    }
    else
    {
        close(fd[0]);
        FILE *f;
        f = fopen("input.txt","w");
        if (f == NULL)
        {
            printf("File could not be created!\n");
            return 1;
        }

        char name[100];
        char roll_number[100];
        char class[100];
        printf("Enter name: ");
        fgets(name,sizeof(name),stdin);
        printf("Enter roll number: ");
        fgets(roll_number,sizeof(roll_number),stdin);
        printf("Enter class: ");
        fgets(class,sizeof(class),stdin);

        fprintf(f,"Name: %sRoll Number: %sClass: %s",name,roll_number,class);

        char file_name[]= "input.txt";
        write(fd[1],file_name,strlen(file_name)+1);
        close(fd[1]);
        fclose(f);
        wait(NULL);
    }
    return 0;
}