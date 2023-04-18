#include<stdio.h>
int main()//(int argc,char argv[])
{
	FILE *fp1=fopen("t.txt","r");
	FILE *fp2=fopen("t2.txt","w");
	char c;
	while((c=fgetc(fp1))!=EOF)
		putc(c,fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
