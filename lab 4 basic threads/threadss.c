#include<stdio.h>
#include<pthread.h>
void fun()
{
printf("Hello this is message from first function\n");
}
void fun1()
{
printf("Hello this is message from second function\n");
}
int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,(void*)fun,NULL);
pthread_create(&t2,NULL,(void*)fun1,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
