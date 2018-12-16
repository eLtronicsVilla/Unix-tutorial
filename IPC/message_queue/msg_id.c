/* 
msgget() -  useful for creating as well as open in message queue
msgsnd() -  useful for sending the data into msg queue
msgrcv() -  useful for receiving the data from the message queue
msgctl() -  useful for doing some control operation on the message queue

*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
int id;
id = msgget(3, IPC_CREAT | 777);  //we can provide any number as key
//message queue is stored in kernel space 
if (id<0)
{
perror ("msgget");
return 0;
}
printf ("id =%d\n",id);
}

