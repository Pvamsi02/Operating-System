#include <stdio.h>
tp1=pid[j];
                                pid[j]=pid[j+1];
                                pid[j+1]=tp1;

                                tp2=at[j];
                                at[j]=at[j+1];
                                at[j+1]=tp2;


                                tp3=bt[j];
                                bt[j]=bt[j+1];
                                bt[j+1]=tp3;
int swap(int* i, int* j){
int temp = *i;
*i = *j;
*j = temp;
}
int main()
{
int n,bt[20],wt[20],tat[20],at[20],p[20];
float awt = 0,atat = 0;
printf("Enter the number of processes(Max 20):");
scanf("%d", &n);
printf("Enter the arrival time for each process: \n");
for (int i = 0; i < n; i++){
printf("P[%d]:", i+1);
p[i] = i + 1;
scanf("%d", &at[i]);
}
printf("Enter the burst time for each process: \n");
for (int i = 0; i < n; i++){
printf("P[%d]:", i+1);
scanf("%d", &bt[i]);
}
for (int i = 0; i < n - 1; i++){
for (int j = i + 1; j < n; j++){
if (at[i] > at[j]){
swap(&at[i], &at[j]);
swap(&p[i], &p[j]);
swap(&bt[i], &bt[j]);
}
}
}
wt[0] = 0;
for (int i = 1; i < n; i++){
wt[i] = wt[i - 1] + bt[i-1];
}
printf("Process No. | Arrival Time | Burst Time | Waiting Time | Turn Around Time\n");
for (int i = 0; i < n; i++){
tat[i] = wt[i] + bt[i];
awt += wt[i];
atat += tat[i];
printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t %d\n", p[i], at[i],
bt[i],wt[i],tat[i]);
}
awt /= n;
atat /= n;
printf("Average waiting time: %f\n", awt);
printf("Average turn around time: %f\n", atat);
return 0;
}
