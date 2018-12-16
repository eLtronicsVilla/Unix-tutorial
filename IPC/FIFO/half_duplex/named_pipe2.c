#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
char s[20];
int fd;
fd = open ("f1", O_RDONLY);
while(1)
{
read(fd,s,sizeof(s));
printf("data = %s\n",s);
}
}
