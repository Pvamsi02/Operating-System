#include<stdio.h>
#include<pthread.h>
struct student
{
char name[20];
int mark1;
int mark2;
};
void *displaycat1(void * s)
{
struct student *st=(struct student *)s;
printf("\nName:%s",st->name);
printf("\nCat 1 mark:%d\n",st->mark1);
}
void *displaycat2(void * s)
{
struct student *st=(struct student *)s;
printf("\nName:%s",st->name);
printf("\nCat 2 mark:%d\n",st->mark2);
}
int main()
{
struct student s1;
printf("Name:");
scanf("%[^\n]s",s1.name);
printf("Mark1:");
scanf("%d",&s1.mark1);
printf("Mark2:");
scanf("%d",&s1.mark2);
pthread_t t1,t2;
pthread_create(&t1,NULL,(void *)displaycat1,&s1);
pthread_create(&t2,NULL,(void *)displaycat2,&s1);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
