#include<stdio.h>
#include<pthread.h>
struct student
{
char name[20];
int cat1;
int cat2;
int total;
};
void * totalcal(void * st)
{
struct student * s2=(struct student *)st;
s2->total=s2->cat1+s2->cat2;
pthread_exit(NULL);
}
int main()
{
int n;
printf("Number of students:");
scanf("%d",&n);
struct student s[n];
for(int i=0;i<n;i++)
{
printf("Name %d:",i+1);
scanf("\n%[^\n]s",s[i].name);
printf("Marks:");
scanf("%d",&s[i].cat1);
scanf("%d",&s[i].cat2);
s[i].total=0;
}
pthread_t t[n];
for(int i=0;i<n;i++)
{
pthread_create(&t[i],NULL,(void*)totalcal,(void*)&s[i]);
printf("Name:%s\n",s[i].name);
pthread_join(t[i],NULL);
printf("Total:%d\n",s[i].total);
}
return 0;
}

