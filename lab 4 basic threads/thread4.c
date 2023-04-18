#include<stdio.h>
#include<pthread.h>
void * fun(void *m)
{
char *msg;
msg=(char *) m;
printf("%s\n",msg);
}
int main()
{
pthread_t t1,t2;
char * m1="Hello (Message 1)";
char * m2="World (Message 2)";
pthread_create(&t1,NULL,(void*)fun,(void*)m1);
pthread_create(&t2,NULL,(void*)fun,(void*)m2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
