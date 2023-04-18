#include<stdio.h>
#include<pthread.h>
void fun1()
{
        FILE *fp=fopen("a.txt","r");
        char c;
        int vc=0;
        while((c=fgetc(fp))!=EOF)
        {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        vc++;
        }
        printf("Vowel Count:%d\n",vc);
        fclose(fp);
}
void fun2()
{
        FILE *fp=fopen("a.txt","r");
        char c;
        int cc=0;
        while((c=fgetc(fp))!=EOF)
        {
        if(c>=97&&c<=122)
        {
                if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u')
                cc++;
        }
        }
        printf("Consonant Count:%d\n",cc);
        fclose(fp);
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
