#include<stdio.h>
#include<pthread.h>
int swap(int* i, int* j)
{
        int temp = *i;
        *i = *j;
        *j = temp;
}
void ctf(int ct[],int bt[],int at[],int n )
{
        int tp1;
        ct[0]=bt[0]+at[0];
        for(int i=1;i<n;i++)
        {
                tp1=0;
                if(ct[i-1]<at[i])
                tp1=at[i]-ct[i-1];
                ct[i]=ct[i-1]+bt[i]+tp1;
        }
}
void tatf(int tat[],int ct[],int at[],int n )
{
        for(int i=0;i<n;i++)
        tat[i]=ct[i]-at[i];
}
void wtf(int wt[],int tat[],int bt[],int n )
{
        for(int i=0;i<n;i++)
        wt[i]=tat[i]-bt[i];
}
void * fcfs()
{
        printf("FCFS\n");
        int n,tp1,tp2,tp3;
        float wta=0,tata=0;
        printf("Number of Process:");
        scanf("%d",&n);
        int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];
        printf("id at bt\n");
        for(int i=0;i<n;i++)
        {
                scanf("%d %d %d",&pid[i],&at[i],&bt[i]);
        }
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n-1-i;j++)
                {
                        if(at[j]>at[j+1])
                        {
                                swap(&at[j+1], &at[j]);
                                swap(&pid[j+1], &pid[j]);
                                swap(&bt[j+1], &bt[j]);
                        }
                }
        }
        ctf(ct,bt,at,n);
        tatf(tat,ct,at,n);
        wtf(wt,tat,bt,n);
        printf("Process Id\tArrival Time\tBrust Time\tCompletion Time\t Turn around Time\tWaiting Time\n");
        for(int i=0;i<n;i++){
                printf("   P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
                wta+=wt[i];
                tata+=tat[i];
        }
        printf("Average Waiting time:%.3f\n",wta/n);
        printf("Average TAT :%.3f\n",tata/n);
}

int main()
{
pthread_t t1;
pthread_create(&t1,NULL,(void*)fcfs,NULL);
pthread_join(t1,NULL);
return 0;
}
