#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
int i,p[2];

if (pipe(p)<0)
{
perror("pipe");
return 0;
}

if (fork())
{
//in parent
char s[200];
printf ("In parent\n");
scanf("%s",s);
write(p[1],s,strlen(s)+1);
}
else
{
char s[200];
printf ("In child\n");
read(p[0],s,sizeof(s));

for (i=0;s[i];i++)
{
if (s[i]>='a' && s[i] <='z')
s[i] = s[i] -32;
}
printf ("data= %s\n",s);
}
}

