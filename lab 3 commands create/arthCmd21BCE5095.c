#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
int n1=atoi(argv[1]);
int n2=atoi(argv[2]);
int res=n1+n2;
printf("Sum:%d+%d=%d\n",n1,n2,res);
res=n1-n2;
printf("Diffrence:%d-%d=%d\n",n1,n2,res);
res=n1*n2;
printf("Multiplication:%d*%d=%d\n",n1,n2,res);
res=n1/n2;
printf("Division:%d/%d=%d\n",n1,n2,res);
return 0;
}
