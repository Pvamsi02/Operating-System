#include<stdio.h>
#include<unistd.h>
int main()
{
	int x=fork();
	if (x==0)
	{
		for(int i=500;i<=1000;i++)
			printf("%d   ",i);
		printf("\n");
	}
	if(x>0)
	{
		for(int i=1;i<=500;i++)
			printf("%d   ",i);
		printf("\n");
	}
	return 0;
}
