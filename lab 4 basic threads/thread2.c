#include<stdio.h>
#include<pthread.h>
void fun1()
{
for(int i=1;i<=10000;i++)
{
printf("%d  ",i);
}
}
void fun2()
{
for(int i=10001;i<=20000;i++)
{
printf("%d  ",i);
}
}
int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,(void *)fun1,NULL);
pthread_create(&t2,NULL,(void *)fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
