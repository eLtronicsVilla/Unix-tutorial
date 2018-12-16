/* what is queue , queue is something there I can write the data , it will be going in buffer , there someone can read the data from other end.
A queue have sender and receiver. The receiver cannot receive the data untill sender will not send it and vice versa.
First process will send the data and receiver can receive the data. 
You have tell to receiver that I am sending the data of type a,b,c. and receiver have to be ready to recieve the data .
There are three system call used to send and receive the data 

In message queue , we have following info :
message key
message id ,
message type ,
message owner,
message size.

system call for message queue:

1.msgsnd - will initialize the queue
2.msgrcv - will be used to receive the message
3.msgctl - control action that is inclusive of deleting the queue

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf
{
long mtype;  //for message type ie: from which process to which process
char msgtxt[200];  // the text data that we are going to send 
};

int main()
{
struct msgbuf msg;
//making an instance of structure
int msgid;

//every message is represented by an id by which we can access the message in the 
key_t key;

//every queue need a key which the sender and receiver will agree upon 
//it is of type key_t as defined in man page of msgsnd

if((key=ftok("msg_snd.c",'b'))==-1)
//ftok function generate the key it will return the key if successful else return 
//ftok is file to key
// we are generating a key with the file that we are creating itself.
{
perror("key"); //if not cretaed perror function will intimate why it's not created
exit(1);
}
if ((msgid=msgget(key,0644 | IPC_CREAT))==-1)
//we are generating a message id through this system call
// if successfull it will return the message id through which we can access the queue
{
perror("msgid");
exit(1);
}
printf("\n the mesid is %d",msgid);
//we are just printing the message id to get a confirmation
printf("Enter the text\n");
//it will ask you to type the data 
msg.mtype=1;
//we are setting the message type here ie. an arrangement between the processes
while(gets(msg.msgtxt),!feof(stdin))
//reading and appending the message typed on the stdin to the queue by the msgsnd function call
{
///////////////////third stage of program///////////////////////

if(msgsnd(msgid,&msg,sizeof(msg),0)==-1)
//here for sending the message we are passing the msgid, address of msg and size o
//as we are not going to use any of the flags , we are marking 0 as 4th argument
// it will return -1 if an error has been creatd
{
perror("msgsnd");
exit(1);
}
}

//////////////////stage 4 of program //////////////////////////

if(msgctl(msgid,IPC_RMID,NULL)==-1)
//to delete the id , when my work is over
{
perror("msgctl");
exit(1);
}
return 0;
} 
