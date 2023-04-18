#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int k=fork();
if(k==0)
{
printf("Child process id:%d\n",getpid());
sleep(20);
}
if(k>0)
{
printf("Parent process id:%d\n",getpid());
exit(0);
}
return 0;
}
