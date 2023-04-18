#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define n 5;
struct data{
int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],p[n];
float avg_fcfs,avg_sjf,avg_pbs;
}
int swap(int* i, int* j)
{
        int temp = *i;
        *i = *j;
        *j = temp;
}
void ctff(int ct[],int bt[],int at[],int n )
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
void ctf(int ct[],int bt[],int at[],int pid[],int n )
{
int min=1000,pos;
ct[0]=at[0] + bt[0];
for(int i=1; i<n; i++)
{
        for(int j=i; j<n; j++)
        {
                if(at[j]<=ct[i-1])
                {
                      if(bt[j]<min)
                      {
                         min=bt[j];
                         pos=j;
                        }
                }
        }
    swap(&pid[i], &pid[pos]);
    swap(&at[i], &at[pos]);
    swap(&bt[i], &bt[pos]);
    min=1000;
    ct[i]=ct[i-1]+bt[i];
  }
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
        ctff(ct,bt,at,n);
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


void * sjf()
{
        printf("SJF\n");
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
                        if(at[j]==at[j+1])
                        {
                                if(bt[j]>bt[j+1])
                                {
                                        swap(&at[j+1], &at[j]);
                                        swap(&pid[j+1], &pid[j]);
                                        swap(&bt[j+1], &bt[j]);
                                }
                        }
                }
        }
        ctf(ct,bt,at,pid,n);
        tatf(tat,ct,at,n);
        wtf(wt,tat,bt,n);
        printf("Process Id\tArrival Time\tBrust Time\tCompletion Time\t Turn around Time\tWaiting Time\n");
        for(int i=0;i<n;i++)
        {
                tat[i]=ct[i]-at[i];
                tata+=tat[i];
                wt[i]=tat[i]-bt[i];
                wta+=wt[i];
                printf("   P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
        printf("Average Waiting time:%.3f\n",wta/n);
        printf("Average TAT :%.3f\n",tata/n);

}

void *PBS_non_preemptive(void *arg)
{
    int i, j;
    int temp_bt, temp_pid;
    for (i = 0; i < max; i++)
    {
        for (j = i + 1; j < max; j++)
        {
            if (bt[i] > bt[j])
            {
                temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
                temp_pid = pid[i];
                pid[i] = pid[j];
                pid[j] = temp_pid;
            }
        }
    }
    wt[0] = 0;
    for (i = 1; i < max; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

int main()
{
    int i, j, k;
    pthread_t thread_FCFS, thread_non_preemptive_SJF, thread_non_preemptive_PBS;
    pthread_create(&thread_FCFS, NULL,(void*) fcfs, NULL);
    pthread_create(&thread_non_preemptive_SJF, NULL,(void*) sjf, NULL);
   // pthread_create(&thread_non_preemptive_PBS, NULL, PBS_non_preemptive, NULL);
    pthread_join(thread_FCFS, NULL);
    pthread_join(thread_non_preemptive_SJF,NULL);
    //pthread_join(thread_non_preemptive_PBS, (void **)&k);

    //printf("Process %d with the longest waiting time in FCFS\n", i);
   // printf("Process %d with the longest waiting time in SJF\n", j);
    //printf("Process %d with the longest waiting time in PBS\n", k);

    return 0;
}
