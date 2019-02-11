//shared memory write 
/* This is the program for shared memory - write 

   This is an another mechanism of interprocess communication.
   This can be done between any two processes. This is they need not be related.
   by default a page of memory (4k byte) would be allocated for shared memory from any process.
   Assume process 1 wants to access its shared memory area. It has to get attached to it first. Though it's PI's memory area. It cannot get access as such.
   only after attaching it can gain access.
   These are three step:
   1. Initialization
   2. Attach
   3.Detach

 */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int retval,shmid;
	char *p = NULL;
	//////////////stage 1 of the program//////////////////////
	/////////////// Initialization if shared memory //////////
	shmid=shmget((key_t)123456789,6,IPC_CREAT | 0666);
	// We are getting the Shm initialized.
	if(shmid <0)
	{
		printf("\n Error due to failure of creation of shared memory ");
		shmid = shmget ((key_t)123456789,6,0666);

		// As it is already created, we are just getting permission for the same
	}
	printf ("\n we are getting the shared memory created %d",shmid);
	p=shmat(shmid,NULL,0);
	//////////////Stage 2 of program///////////////////
	/////////// attached to the shared memory ///////////
	// on success shmat() return the address of the attached shared memory segment of 
	// so why we are declaring void *memory = NULL , in the start of the code 
	// wee are attaching the process of the shared memory
	// shared memory create in user space with process p1 address space 
	memset(p,'\0',6);
	// we are cleaning befiore using
	memcpy(p,"hello",5);
	//we are now writing the content.

	if (p == NULL)
	{
		printf ("\n attachment failure , sorry");
		return 0;
	}
	//p=(char *)memory;
	// we are entering the address space .
	//so we need to specify the data type .
	// here we are sending the character , so w need to cast it to char 

	//////////// stage 3 of program /////////////
	//dataching as we have already written.
	retval = shmdt(p);
	if (retval < 0)
	{
		printf("\n Suffered Detachment");
		return 0;
	}
}


