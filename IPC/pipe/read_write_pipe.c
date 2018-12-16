#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
int p[2];          // integer for file descriptor
if (pipe(p) < 0)   //pipe system call will return two file discriptor
{                  // for failure case this will return -1
perror("pipe");
return 0;
}
printf("read end = %d\n",p[0]);
printf("write end = %d\n",p[1]);

if (fork())  //if fork == 0 -> child process and if fork() !=0 --> parent process
{
//parent
char s[10];
printf ("In parent ...\n");
printf("Enter the data\n");
scanf ("%s", s);
write(p[1],s,strlen(s)+1);
}
else
{
//child
char s[10];
printf("In child...\n");
read(p[0],s,sizeof(s));
printf("data : %s\n",s);
}
}
