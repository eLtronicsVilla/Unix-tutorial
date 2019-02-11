// shared memory read

/* 
   1. Initialized 
   2. attach
   3. Detach
 */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int retval,shmid;
	char *memory = NULL;
	char *p;

	///////////////// stage 1 of the program ///////////////////
	// Intialization of shared memory.

	shmid = shmget((key_t)123456789,6,IPC_CREAT | 0666);
	//We are getting the Shm initialized
	if (shmid < 0 )
	{
		printf ("\n we are getting the shared memory created %d",shmid);
		return 0;
	}
	//////////////// Stage 2 of the program //////////
	///// attachment to the shared memory.
	memory = shmat(shmid,NULL,0);
	// we are attaching the process to the shared memory
	if (memory == NULL)
	{
		printf ("attachn=ment failure sorry\n");
		return 0;
	}
	//p=(char *)memory;
	// we are entering the address space .
	// so we need to specify the data type
	// here we are sending thr characters. So we need to cast it to char
	printf ("\n message is %s \n",memory);
	// we are priintig it here 

	/////////// Stage 3 of program //////////
	/// deataching ad we have already written

	retval = shmdt(p);
	if (retval <0)
	{
		printf ("\n suffered detachment");
		return 0;
	}
	retval = shmctl(shmid,IPC_RMID, NULL);
	return 0;
}

