/*Write a C program that accepts an integer n, uses the child process to print Fibonacci 
numbers up to n, and uses the parent process to print Armstrong numbers detected by the 
program from 1 through n.*/

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
		printf("Fibonacci numbers: ");

		int a = 0;
		int b = 1;
		while(a <= n)
		{
			printf("%d ",a);
			int c = a + b;
			a = b;
			b = c;
		}
		printf("\n");
	}
	else
	{
		wait(NULL);
		printf("Parent Process!\n");
		printf("Armstrong numbers: ");

		for(int i=1;i<=n;i++)
		{
			int temp = i;
			int digits = 0;
			while(temp != 0)
			{
				digits++;
				temp /= 10;
			}

			temp = i;
			int sum = 0;
			while(temp != 0)
			{
				int digit = temp % 10;
				int power = 1;
				for(int j=0;j<digits;j++)
				{
					power *= digit;
				}
				sum += power;
				temp /= 10;
			}
			if(sum == i)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}