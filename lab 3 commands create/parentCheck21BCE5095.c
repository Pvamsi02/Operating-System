#include<stdio.h>
#include<unistd.h>
int main()
{
for(int i=0;i<3;i++)
{
int k=fork();
if(k==0)
{
printf("Child %d process id: %d and his parent process id: %d\n",i+1,getpid(),getppid());
return 0;
}
}
return 0;
}
