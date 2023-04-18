#include<stdio.h>
#include<unistd.h>
int main()
{
	int n;
	scanf("%d",&n);
	int x=fork();
	if(x==0)
	{
		printf("\n\nChild process 1 id: %d\n",getpid());
		if(n%2==0)
		printf("Given number is even\n");
		else
		printf("Given number is odd\n");
		return 0;
	}
	int y=fork();
	if(y==0)
	{

		int c=0;
		for(int i=2;i<n;i++)
		{
		if(n%i==0)
		c++;
		}
		printf("\n\nChild process 2 id: %d\n",getpid());
		if(c==0)
		printf("Prime Number\n");
		else
		printf("Composite Number\n");
		return 0;
	}
	int z=fork();
	if(z==0)
	{
		printf("\n\nChild process 3 id: %d\n",getpid());
		if(n%7==0)
		printf("Number is divisible by 7\n");
		else
		printf("Number is not divisible by 7\n");
		return 0;
	}
	return 0;
}
