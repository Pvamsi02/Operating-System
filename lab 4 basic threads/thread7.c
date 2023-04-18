#include<stdio.h>
#include<pthread.h>
void * display(void *msg)
{
char *message;
message=(char*)msg;
printf("Message:%s\nThread_id:%ld\n\n",message,pthread_self());
}
int main()
{
char * msg1="Hello message 1";
char * msg2="Hello message 2";
pthread_t t1,t2;
pthread_create(&t1,NULL,(void*)display,(void *)msg1);
pthread_create(&t1,NULL,(void*)display,(void *)msg2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
