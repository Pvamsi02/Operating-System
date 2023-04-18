#include <stdio.h>
#include<pthread.h>
#define MAX 9999;
struct proc
{

        int no,at,bt,ct,wt,tat,pri,status;
};
struct proc read(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Arrival Time: ");
    scanf("%d", &p.at);
    printf("Enter Burst Time: ");
    scanf("%d", &p.bt);
    return p;
}
struct proc readp(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Arrival Time: ");
    scanf("%d", &p.at);
    printf("Enter Burst Time: ");
    scanf("%d", &p.bt);
    printf("Enter Priority: ");
    scanf("%d", &p.pri);
    p.status = 0;
    return p;
}
void *fcfs()
{
    struct proc p[10], tmp;
    float avgtat = 0, avgwt = 0;
    int n, ct = 0;
    printf("\n<--FCFS Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
    printf("\nProcessNo\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        ct += p[i].bt;
        p[i].ct = ct;
        p[i].tat = p[i].ct - p[i].at;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].no, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].wt);
    }
    avgtat /= n, avgwt /= n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", avgtat, avgwt);
}
void *sjf()
{
    int n, j, min = 0;
    float avgtat = 0, avgwt = 0;
    struct proc p[10], temp;
    printf("\n<--SJF Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);
    for (int i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
    for (j = 1; j < n && p[j].at == p[0].at; j++)
        if (p[j].bt < p[min].bt)
            min = j;
    temp = p[0];
    p[0] = p[min];
    p[min] = temp;
    p[0].at = p[0].at;
    p[0].ct = p[0].at + p[0].bt;
    for (int i = 1; i < n; i++)
    {
        for (j = i + 1, min = i; j < n && p[j].at <= p[i - 1].ct; j++)
            if (p[j].bt < p[min].bt)
                min = j;
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
        if (p[i].at <= p[i - 1].ct)
            p[i].at = p[i - 1].ct;
        else
            p[i].at = p[i].at;
        p[i].ct = p[i].at + p[i].bt;
    }
    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].no, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].wt);
    }
    avgtat /= n, avgwt /= n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", avgtat, avgwt);
}
void *pbs()
{
    int n, s, ct = 0, remaining;
    struct proc p[10], temp;
    float avgtat = 0, avgwt = 0;
    printf("\n<--Smallest Priority First Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        p[i] = readp(i + 1);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
    p[9].pri = MAX;
    remaining = n;
    printf("\nProcessNo\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n");
    for (ct = p[0].at; remaining != 0;)
    {
        s = 9;
        for (int i = 0; i < n; i++)
            if (p[i].at <= ct && p[i].status != 1 && p[i].pri < p[s].pri)
                s = i;
        p[s].ct = ct = ct + p[s].bt;
        p[s].tat = p[s].ct - p[s].at;
        avgtat += p[s].tat;
        p[s].wt = p[s].tat - p[s].bt;
        avgwt += p[s].wt;
        p[s].status = 1;
        remaining--;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[s].no, p[s].at, p[s].bt, p[s].pri, p[s].ct, p[s].tat, p[s].wt, p[s].wt);
    }
    avgtat /= n, avgwt /= n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", avgtat, avgwt);
}
int main()
{
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, (void *)fcfs, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, (void *)sjf, NULL);
    pthread_join(t2, NULL);
    pthread_create(&t3, NULL, (void *)pbs, NULL);
    pthread_join(t3, NULL);

    return 0;
}
