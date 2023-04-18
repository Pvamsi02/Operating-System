#include <stdio.h>
#include <pthread.h>
struct student
{
    char name[20];
    int cat1;
    int cat2;
    int total;
} s1;
void *totalcal(void *st)
{
    struct student *s2 = (struct student *)st;
    s2->total = s2->cat1 + s2->cat2;
    pthread_exit(NULL);
}
int main()
{
    scanf("%[^\n]s", s1.name);
    scanf("%d", &s1.cat1);
    scanf("%d", &s1.cat2);
    pthread_t t1;
    pthread_create(&t1, NULL, (void *)totalcal, (void *)&s1);
    printf("Name:%s\n", s1.name);
    printf("Total(before join):%d\n", s1.total);
    pthread_join(t1, NULL);
    printf("Total(after join):%d\n", s1.total);
    return 0;
}

