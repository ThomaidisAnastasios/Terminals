#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char const *argv[])
{
	key_t key = 709; // Key for creating mutex memory. We use our registry (uowm).
	int SemaphoreID, SemaphoreAttach, X1 = 0;

	SemaphoreID = shmget(key, 10, 0600 | IPC_CREAT);

	if (SemaphoreID == -1)
	{
		perror("Error at obtaining Semaphore ID. \n");
		fflush(stdout);
		exit(1);
	}
	else
	{
		printf("Semaphore ID obtained succesfully. \n");
		fflush(stdout);
	}

	SemaphoreAttach = shmat(SemaphoreID, (char *) 0, 0);

	if (SemaphoreAttach ==  -1)
	{
		perror("Error at attaching shared memory. \n");
		fflush(stdout);
	}
	else
	{
		printf("Shared memory attached syccesfully. \n");
		fflush(stdout);
	}

	sleep(5);

	// We use mutex to lock shared memory.
	// Inc 10 address 0 of shared memory and store at same address.
	// Value printed at end should be 5.	

	return 0;
}