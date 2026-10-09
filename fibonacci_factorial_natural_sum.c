/*Write a C program that accepts an integer n, uses child processes to print the first n Fibonacci terms and calculate n!, while the original parent calculates the sum of the first n natural numbers. Use wait() to synchronize the processes.*/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	fflush(stdout);
	int pid1 = fork();
	if (pid1 == 0)
	{
		int a = 0, b = 1;
		printf("First %d Fibonacci terms: ", n);
		for (int i = 0; i < n; i++)
		{
			printf("%d ", a);
			int next = a + b;
			a = b;
			b = next;
		}
		printf("\n");
		return 0;
	}

	int pid2 = fork();
	if (pid2 == 0)
	{
		int factorial = 1;
		for (int i = 1; i <= n; i++)
		{
			factorial *= i;
		}
		printf("Factorial of %d is %d\n", n, factorial);
		return 0;
	}

	wait(NULL);
	wait(NULL);

	printf("Parent Process!\n");
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	printf("Sum of the first %d natural numbers is %d\n", n, sum);

	return 0;
}
 