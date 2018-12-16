#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1,fd2;
	char s1[200],s2[200];
	fd1 = open("fifo1",O_RDWR);
	fd2 = open("fifo2",O_RDWR);
	if (fork() == 0)
	{
		while(1)
		{	
			read(fd1,s1,sizeof(s1));
			printf ("data = %s\n",s1);
		}
	}
	else
	{
		while(1)
		{	printf("Enter the string in p2\n");
			gets(s2);
			write(fd2,s2,strlen(s2)+1);
		}
	}
close(fd1);
close(fd2);
}

