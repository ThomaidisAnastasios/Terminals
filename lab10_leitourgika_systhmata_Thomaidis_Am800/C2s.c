#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
	key_t k = 709; 
	size_t s = 50; 
	int SMC;
	char *SMP, *SMPC;

	SMC = shmget(k, s, IPC_CREAT | 0666);

	if (SMC == -1) 
	{
		printf("Creation false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Creation true.\n");
		fflush(stdout);
	}

	SMP = shmat(SMC, NULL, 0); 
	SMPC = SMP; 

	if (SMP == (char *) -1)
	{
		printf("Attachment false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Attached true.\n");
		fflush(stdout);
	}

	*SMP++ = "Tasos";
	*SMP = 0;

	while(*SMP == 0) 
	{
		sleep(1);
	}

	printf("Message:%c .\n",*SMP);
	fflush(stdout);

	shmdt(NULL);
	printf("Dattachment true.\n");
	fflush(stdout);

	msgctl(SMC, IPC_RMID, (struct shmid_ds *) 0);
	printf("Destruction true.\n");
	fflush(stdout);

	return 0;
}
