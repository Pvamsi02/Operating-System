#include<stdio.h>
#include<pthread.h>
struct student
{
char name[20];
int mark1;
int mark2;
};
void *display(void * s)
{
struct student *st=(struct student *)s;
printf("\nName:%s",st->name);
printf("\nCat 1 mark:%d",st->mark1);
printf("\nCat 2 mark:%d\n",st->mark2);
}
int main()
{
int n;
printf("Number of Students:\n");
scanf("%d",&n);

struct student s[n];
for(int i=0;i<n;i++)
{
printf("Name %d:",i+1);
scanf("\n%[^\n]s",s[i].name);
printf("Mark1:");
scanf("%d",&s[i].mark1);
printf("Mark2:");
scanf("%d",&s[i].mark2);
}

pthread_t t[n];
for(int i=0;i<n;i++)
pthread_create(&(t[i]),NULL,(void *)display,&s[i]);

for(int i=0;i<n;i++)
pthread_join(t[i],NULL);
return 0;
}
