#include <stdio.h>
#include <unistd.h>
int main()
{
    int i;
    printf("Main ID: %d\n", getpid());
    /*	int a=fork();*/
    for (i = 0; i < 3; i++)
    {
        int a = fork();
        if (a == 0)
        {
            /*			printf("Process id: %d\n",getpid());*/
            printf("Parent id: %d\n", getppid());
        }
    }
}