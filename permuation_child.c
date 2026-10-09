/*Write a C program that accepts a string, creates a child process to find and print
all permutations of the string, and makes the parent wait for the child to complete.*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void permutation(char a[], int start, int end)
{
	if(start == end)
	{
		printf("%s\n",a);
		return;
	}

	for(int i=start;i<=end;i++)
	{
		char temp = a[start];
		a[start] = a[i];
		a[i] = temp;

		permutation(a,start+1,end);

		temp = a[start];
		a[start] = a[i];
		a[i] = temp;
	}
}

int main()
{
	char a[20];
	printf("Enter the string: ");
    fgets(a,sizeof(a),stdin);
    a[strcspn(a,"\n")] = '\0';
	fflush(stdout);

	int pid = fork();

	if(pid < 0)
	{
		printf("Process creation failed!\n");
		return 0;
	}
	else if(pid == 0)
	{
		printf("Child process!\n");
		printf("Permutations:\n");
		permutation(a,0,strlen(a)-1);
	}
	else
	{
		wait(NULL);
		printf("Parent Process!\n");
	}
	return 0;
}