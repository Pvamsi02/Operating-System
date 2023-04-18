#include<stdio.h>
#include<stdlib.h>
int main()
{
system(" sysctl -a | grep threads-max");
return 0;
}
