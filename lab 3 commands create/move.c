#include<stdio.h>
int main(int argc,char* argv[])
{
	FILE *fp1=fopen(argv[1],"r");
	FILE *fp2=fopen(argv[2],"w");
	char c;
	while(feof(fp1))
	{
		c=fgetc(fp1);
		putc(c,fp2);
	}
	
	fclose(fp1);
	fclose(fp2);
	remove(argv[1]);
	return 0;
}
