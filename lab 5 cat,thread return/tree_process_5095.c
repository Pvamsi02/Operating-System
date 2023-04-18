#include <stdio.h>
#include <unistd.h>
int main()
{
int par=fork();
if(par==0)
{
        for (int i = 0; i < 3; i++)
        {
        int l1 = fork();
        if (l1 == 0)
        {
                for (int j = 0; j < 2; j++)
                {
                int l2 = fork();
                if (l2 == 0)
                {
                printf("L2 child id:%d\tits parent in L1 id:%d\n", getpid(), getppid());
                return 0;
                }
                if(l2>0)
                sleep(1);
                }
                printf("L1 child id:%d\tits parent in L0 id:%d\n", getpid(), getppid());
                return 0;
        }
        if(l1>0)
        sleep(4);
        }
        printf("L0 the main child process id:%d\tit\'s parent main() id:%d\n", getpid(), getppid());
        return 0;
}
if(par>0)
{
sleep(15);
printf("main() process id:%d\n",getpid());
}
return 0;
}
