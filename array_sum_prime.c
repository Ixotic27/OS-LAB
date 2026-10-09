/*Write a C program that accepts an array of integers, creates a child process, calculates 
the sum of the array in the child, checks whether the sum is prime, and makes the parent 
wait for the child to complete.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);

	int a[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	int pid = fork();

	if(pid < 0)
	{
		printf("Process creation failed!\n");
		return 0;
	}
	else if(pid == 0)
	{
		printf("Child process!\n");
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			sum += a[i];
		}
		printf("Sum: %d\n",sum);

		int prime = 1;
		if(sum < 2)
		{
			prime = 0;
		}
		else
		{
			for(int i=2;i*i<=sum;i++)
			{
				if(sum%i == 0)
				{
					prime = 0;
					break;
				}
			}
		}

		if(prime == 1)
		{
			printf("Sum is prime!\n");
		}
		else
		{
			printf("Sum is not prime!\n");
		}
	}
	else
	{
		wait(NULL);
		printf("Parent Process!\n");
	}
	return 0;
}