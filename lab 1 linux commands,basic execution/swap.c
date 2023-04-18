#include<stdio.h>
void swapval(int n1,int n2){
int t=n1;
n1=n2;
n2=t;
}
void swapaddr(int *n1,int *n2){
int t=*n1;
*n1=*n2;
*n2=t;
}

int main()
{
int a=100;
int b=200;
printf("Actual numbers: %d,%d\n",a,b);
swapval(a,b);
printf("After swap using pass by value: %d %d\n",a,b);
swapaddr(&a,&b);
printf("After swap using pass by Reference: %d %d\n",a,b);
return 0;
}
