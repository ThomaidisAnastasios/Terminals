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
	char *SMP, *SMPCOPY, msg[];

	SMC = shmget(k, s, IPC_CREAT | 0666);

	if (SMC == -1) 
	{
		printf("Creation false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Creation true\n");
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

	printf("Give msg.\n");
	fflush(stdout);
	fgets(msg, s, stdin);

	*SMP++ = msg;
	*SMP = 1;

	return 0;
}
