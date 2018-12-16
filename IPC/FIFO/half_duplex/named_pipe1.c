/* Named pipe is known as FIFO ( First in first out )

mkfifo -> you can create file by this command or by using system command ( cd filename)

mknode -> only it create FIFO by this

mknode() - > character special file , block special file , fifo it can create.

Look for the man page for FIFO

*/
// named pipe is used for independent process

// for process p1

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
char s[20];
int fd;
if(mkfifo("f1",0644) <0)
{
perror("mkfifo");
}
printf ("before.......\n");
fd=open("f1",O_WRONLY);
printf ("After.....\n");
printf ("Enter the data...\n");
scanf ("%s",s);
write (fd,s,strlen(s)+1);
} 
