#include<stdio.h>
int main(int argc,char* argv[])
{
	FILE *fp1=fopen(argv[1],"r");
	FILE *fp2=fopen(argv[2],"w");
	char c;
	while((c=fgetc(fp1))!=EOF)
	{
		putc(c,fp2);
	}
	fclose(fp1);
	remove(argv[1]);
	fclose(fp2);
	return 0;
}


