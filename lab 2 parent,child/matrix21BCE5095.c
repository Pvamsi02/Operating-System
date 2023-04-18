#include<stdio.h>
#include<unistd.h>
int main()
{
	int k=fork();
	int a[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    	int b[3][3] = {{9, 8, 7},{6, 5, 4},{3, 2, 1}};
	if(k==0)
	{
		printf("Child process id:%d\n Matrix Substraction:\n",getpid());
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			printf("%d\t",a[i][j]-b[i][j]);
			printf("\n");
		}
	}
	if(k>0)
	{
		printf("Parent process id: %d\n Matrix Addition:\n",getpid());
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			printf("%d\t",a[i][j]+b[i][j]);
			printf("\n");
		}
		
	}
	return 0;
}
