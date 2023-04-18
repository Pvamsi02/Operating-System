#include<stdio.h>
#include<stdbool.h>
#define row 5
#define col 4
void initailFinal(bool final[])
{
for(int i=0;i<row;i++)
        final[i]=false;
}
void print_2d(int a[row][col])
{
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<col;j++)
                        printf("%d ",a[i][j]);
                printf("\n");
        }
        printf("\n");
}
void print_1d(int a[col])
{
for(int i=0;i<col;i++)
        printf("%d ",a[i]);
}
int compare(int a[col],int b[col])
{
        int x=0;
                for(int i=0;i<col;i++)
                {
                
                if(a[i]<=b[i])
                {
                //printf("compare");
                x++;
                }
                
                }
                if(x==col)
                return 1;
                else
                return 0;
}

int bankers(int allocation[row][col],int request[row][col],int available[col])
{
//printf("Bankers");
        int cavailable[col];
        int x=row;
        bool final[row];
                initailFinal(final);
                for(int i=0;i<col;i++)
                    cavailable[i]=available[i];
        int j=0,count=0;
                for(int k=0;k<row;k++)
                {
                    for(int i=0;i<row;i++)
                    {
                        if(final[i]==false)
                        {
                            count=0;
                            for(int j=0;j<col;j++)
                            {
                                if(cavailable[j]>=request[i][j])
                                    count++;
                            }
                            if(count==col)
                            {
                                for(int j=0;j<col;j++)
                                {
                                cavailable[j]+=allocation[i][j];
                                }
                                final[i]=true;
                                x--;
                            }
                        }
                    }
                }

                for(int i=0;i<row;i++)
                {
                if(final[i]==0)
                x=1;
                }
                if(x!=1)
                {
                return 0;
                }
                else
                return 1;
}

void process(int x,int resources_request[][col],int allocation[row][col],int request[row][col],int available[col],int k)
{
        int t;
        int new_allocation[row][col],new_request[row][col],new_available[col];
                for(int i=0;i<row;i++)
                {
                        for(int j=0;j<col;j++)
                        {
                        new_allocation[i][j]=allocation[i][j];
                        new_request[i][j]=request[i][j];
                        new_available[j]=available[j];
                        }
                }
        if(compare(resources_request[k],new_available))
                {
                for(int i=0;i<col;i++)
                {
                t=resources_request[k][i];
                new_allocation[x][i]=new_allocation[x][i]+t;
                new_available[i]=new_available[i]-t;
                new_request[x][i]=new_request[x][i]-t;
                }
                
        if(bankers(new_allocation,new_request,new_available)==0)
        {
                printf("\nProcess %d request is safe to add.\n",x+1);

                for(int i=0;i<col;i++)
                {
                t=resources_request[k][i];
                allocation[x][i]=allocation[x][i]+t;
                available[i]=available[i]-t;
                request[x][i]=request[x][i]-t;
                }
        }
                
                else 
                printf("\nProcess %d request makes a deadlock.\n",x+1);
                }
                else
                printf("\nProcess %d Request cannot be accepted due to less resources available.\n",x+1);
}

void resourceRequest(int allocation[row][col],int request[row][col],int available[col])
{
        int n,x;
                printf("No of requests:");
                scanf("%d",&n);
        int process_request[n];
        int resources_request[n][col];
                for(int i=0;i<n;i++)
                {
                printf("Process id:");
                scanf("%d",&process_request[i]);
                printf("Request resources:");
                for(int j=0;j<col;j++)
                scanf("%d",&resources_request[i][j]);
                }
                for(int i=0;i<n;i++)
                {
                x=process_request[i]-1;
        process(x,resources_request,allocation,request,available,i);
                }
}

int main()
{
        int allocation[row][col]={3,0,1,4,2,2,1,0,3,1,2,1,0,5,1,0,4,2,1,2};//{{10,1,0},{2,0,0},{3,0,22},{2,1,1},{10,0,2}};
                //printf("Allocation Matrix:\n");
                //print_2d(allocation);
        int max[row][col]={5,1,1,7,3,2,1,1,3,3,2,1,4,6,1,2,6,3,2,5};//{{17,5,3},{3,2,2},{9,0,22},{2,2,2},{16,3,3}};
                //printf("Maximum Resource Matrix:\n");
                //print_2d(max);
        int request[row][col];
        int available[col]={0,3,0,1};//={3,3,2};
                for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                request[i][j]=max[i][j]-allocation[i][j];
        resourceRequest(allocation,request,available);
return 0;
}
