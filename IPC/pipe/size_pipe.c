// In the case read() system call block the process if the pipe is empty
// In the case write() system call block the process if the pipe is full

/*
if all the file descriptor refering to the write end of file have been closed and attempt to read from file have been closed and attempt to read from file.

If all the file descriptor refering to the read have been closed then write will cause a SIGPIPE signal to be generated for calling process.

*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int p[2],c=0;
char ch ='a';
//pipe(p);
pipe2(p,O_NONBLOCK);
while(write(p[1], &ch,1)!=-1) //when pipe will be free return -1
{
c++;
}
printf("%d\n",c);
printf("thanks...\n");
}

