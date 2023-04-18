#include<stdio.h>
#include<pthread.h>
int primefactor(void* no)
{
        int *n=(int*)no;
        printf("Prime factors: ");
        for(int i=2;i<=*n;i++)
        {
        if(*n%i==0)
        printf("%d  ",i);
        }
        pthread_exit(NULL);
}
void fibonacci(void *no)
{
        int t0=0,t1=1,tn;
        int *n=(int*)no;
        if(*n==0||*n==1)
        printf("\nFibonacci Number:%d\n",*n);
        else
        {
        tn=t0+t1;
        for(int i=3;i<=*n;i++)
        {
        t0=t1;
        t1=tn;
        tn=t0+t1;
        }
        printf("\nFibonacci Number:%d\n",t1);
        }
        pthread_exit(NULL);
}
int main()
{
int n;
printf("Number:");
scanf("%d",&n);
pthread_t t1,t2;
pthread_create(&t1,NULL,(void*)primefactor,&n);
pthread_create(&t2,NULL,(void*)fibonacci,&n);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
