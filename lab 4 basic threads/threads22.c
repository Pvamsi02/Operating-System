#include<stdio.h>
#include<pthread.h>
void *fun1(void *n)
{
int *val;
val=(int *)n;
for(int i=*val;i<*val+10000;i++)
{
printf("%d  ",i);
}
}
int main()
{
pthread_t t1,t2;
int n1=1,n2=10001;
pthread_create(&t1,NULL,(void *)fun1,&n1);
pthread_create(&t2,NULL,(void *)fun1,&n2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
