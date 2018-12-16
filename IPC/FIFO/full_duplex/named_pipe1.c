#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char s1[200],s2[200];
	int fd1,fd2;
	//mkfifo("f1",0644);
	//mkfifo("f2",0644);
	fd1 = open("fifo1",O_RDWR);
	fd2 = open("fifo2",O_RDWR);
	if (fork()==0)
	{
		while(1)
		{
			printf("Enter the string in p1\n");
			gets(s1);
			write(fd1,s1,strlen(s1)+1);
		}
	}
	else 
	{
		while(1)
		{
			read(fd2,s2,sizeof(s2));
			printf ("Data= %s\n",s2);
		}
	}
close(fd1);
close(fd2);
}
