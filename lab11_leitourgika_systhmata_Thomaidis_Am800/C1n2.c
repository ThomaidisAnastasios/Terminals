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
	key_t k = 709; 
	int Sid, SA;

	Sid = shmget(k, 10, 0600 | IPC_CREAT);

	if (Sid == -1)
	{
		perror("ID not obtained\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("ID obtained.\n");
		fflush(stdout);
	}

	SA = shmat(Sid, (char *) 0, 0);

	if (SA ==  -1)
	{
		perror("Memory attachment false.\n");
		fflush(stdout);
	}

	else
	{
		printf("Memory attachment true.\n");
		fflush(stdout);
	}

	sleep(5);	

	return 0;
}
