#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int k,i,vowelCount=0,consonantCount=0;
	char s[20];
	scanf("%s",s);
	k=fork();
	if(k==0)
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]=='a'||'e'||'i'||'o'||'u')
			vowelCount++;
		}
		printf("Child process id:%d\nNo of vowels found in child process=%d\n",getpid(),vowelCount);
	}
	if(k>0)
	{
		for(i=0;i<strlen(s);i++)
		{
			if((s[i]>'a'&& s[i]<='z')&&(s[i]!='a'||'e'||'i'||'o'||'u'))
			consonantCount++;
		}
		printf("Parent process id:%d\nNo of consonants found in parent process=%d\n",getpid(),consonantCount);
	}
	return 0;
}
