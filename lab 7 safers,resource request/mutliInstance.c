#include<stdio.h>
#include<stdbool.h>
#define row 3
#define col 2
bool final[row];
void initailFinal()
{
for(int i=0;i<row;i++)
final[i]=false;
}
void pout(int a[row][col])
{
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
printf("%d ",a[i][j]);
printf("\n");
}
printf("\n");
}

void pr(int a[col])
{

for(int i=0;i<col;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}

int main()
{
int allocation[row][col]={{1,0},{0,1},{0,1}};
printf("Allocation Matrix:\n");
pout(allocation);
int request[row][col]={{0,1},{1,0},{1,0}};
printf("Request Matrix:\n");
pout(request);
int available[col]={0,0};
int cavailable[col];
int x=row;
initailFinal();

for(int i=0;i<col;i++)
{
cavailable[i]=available[i];
}

int count=0;
for(int k=0;k<row;k++)
//while(x!=0)
{
for(int i=0;i<row;i++)
{
if(final[i]==false)
{
        count=0;
        for(int j=0;j<col;j++)
        {
                if(cavailable[j]>=request[i][j])
                {
                        count++;
                }
        }
        if(count==col)
        {
                printf("P[%d]->",i+1);
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
printf("No Dead lock\nTotal resources left:");
pr(cavailable);
}

else
printf("Dead lock occurs");
//pout(request);
return 0;
}
