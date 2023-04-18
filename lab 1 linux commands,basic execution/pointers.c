#include<stdio.h>
void passVal(int n)
{
n=n*100;
}
void passAddr(int *n)
{
*n=*n*100;
}
int main()
{
int n=5095;
printf("Actual value :%d\n",n);
passVal(n);
printf("Pass by Value :%d\n",n);
passAddr(&n);
printf("Pass by Reference or Address :%d\n",n);
return 0;
}
