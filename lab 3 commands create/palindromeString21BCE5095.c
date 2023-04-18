#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
        int flag=0;
        char *str=argv[1];
        int length=strlen(str);
        for (int i=0;i<length/2;i++)
        {
                if(str[i]!=str[length-i-1])
                {
                        flag=1;
                        break;
                }
        }
        if(flag==1)
        printf("Not a Palindrome String.\n");
        else
        printf("Palindrome String.\n");
        return 0;
}
