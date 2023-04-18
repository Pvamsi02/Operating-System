#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int k=fork();
if (k==0)
{
printf("Child process id: %d when created\n",getpid());
sleep(5);
printf("Child process id: %d after becoming zombie process\n",getpid());
exit(0);
}
if (k>0)
{
printf("Parent process id: %d\n",getpid());
sleep(10);
}
return 0;
}
