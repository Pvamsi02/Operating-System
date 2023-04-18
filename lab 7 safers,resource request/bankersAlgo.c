#include<stdio.h>
#include<stdbool.h>
#define row 5
#define col 4
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
}

int main()
{
int allocation[row][col]={3,0,1,4,2,2,1,0,3,1,2,1,0,5,1,0,4,2,1,2};//{{10,1,0},{2,0,0},{3,0,22},{2,1,1},{10,0,2}};={{10,1,0},{2,0,0},{3,0,22},{2,1,1},{10,0,2}};
printf("Allocation Matrix:\n");
pout(allocation);
int max[row][col]={5,1,1,7,3,2,1,1,3,3,2,1,4,6,1,2,6,3,2,5};//{{17,5,3},{3,2,2},{9,0,22},{2,2,2},{16,3,3}};={{17,5,3},{3,2,2},{9,0,22},{2,2,2},{16,3,3}};
printf("Maximum Resource Matrix:\n");
pout(max);
int request[row][col];
int available[col]={0,3,0,1};//={3,3,2};={3,3,2};
int cavailable[col];
int x=row;

for(int i=0;i<row;i++)
for(int j=0;j<col;j++)
request[i][j]=max[i][j]-allocation[i][j];
printf("Request matrix:\n");
pout(request);

initailFinal();

for(int i=0;i<col;i++)
{
cavailable[i]=available[i];

}

//pr(cavailable);


int j=0,count=0;
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
                //printf("P[%d]->",i+1);
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
//pr(cavailable);
}

else
printf("Dead lock occurs");
//pout(request);
return 0;
}
