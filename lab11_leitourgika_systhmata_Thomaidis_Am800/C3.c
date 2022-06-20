#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <semaphore.h>

int main(int argc, char const *argv[])
{
	sem_t m;
	key_t k = 709;
	size_t s = 20;
	pid_t pid1, pid2, pid3, currentPID;
	int cP = 0, c1 = 0, c2 = 0, c3 = 0, MI, MD, SMid, MLC, MUC, SMAA;

	MI = sem_init(&m, 1, 1); 

	if (MI == -1)
	{
		perror("Initialaization false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Initialization true.\n");
		fflush(stdout);
	}

	SMid = shmget(k, s, 0666 | IPC_CREAT); 

	if (SMid == -1)
	{
		perror("Shared memory creation false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Shared memory creation true.\n");
		fflush(stdout);
	}

	SMAA = shmat(SMid, 0, 0666 | IPC_CREAT); 

	if (SMAA == -1)
	{
		perror("Shared memory attchemend false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Shared memory attachement true.\n");
		fflush(stdout);
	}

	p1 = fork();
	p2 = fork();
	p3 = fork();

	if (p1 == -1) 
	{
		perror("Child n1 crteation flase\n");
		fflush(stdout);
		exit(1);
	}

	else if (p2 == -1)
	{
		perror("child n2 creation flase.\n");
		fflush(stdout);
		exit(1);
	}

	else if (p3 == -1)
	{
		perror("Child n3 creation failed.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Childs creation true.\n");
		fflush(stdout);
	}

	while (1)
	{
		if (p1 != 0 && p2 != 0 && p3 != 0)
		{
			sleep(3);

			currentPID = getp();

			MLC = sem_wait(&m);

			if (MLC == -1)
			{
				perror("Shared memory lock false.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Shared memory lock true.\n");
				fflush(stdout);
			}

			printf("P: %d Count at critical point: %d. \n", cP, cP);
			cP++;

			MUC = sem_post(&m);

			if (MUC == -1)
			{
				perror("Shared memory false.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Shared memory not locked true.\n");
				fflush(stdout);
			}

			printf("PID: %d critical section true.\n", cP);
			fflush(stdout);
			}

		else if (p1 == 0)
		{
			sleep(3);

			cP = gp();

			MLC = sem_wait(&m);

			if (MLC == -1)
			{
				perror("Shared memory lock false.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Shared memory lock true.\n");
				fflush(stdout);
			}

			printf("PID: %d count at critical point %d. \n",cP, c1);
			c1++;

			MUC = sem_post(&m);

			if (MUC == -1)
			{
				perror("Shared memory still locked.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Shared memory unlcoked true.\n");
				fflush(stdout);
			}

			printf("PID: %d leaving crit senction \n", cP);
			fflush(stdout);
		}

		else if (p2 == 0) 
		{
			sleep(3);

			cP = gp();

			MLC = sem_wait(&m);

			if (MLC == -1)
			{
				perror("Shared memory locked false.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Memory lock true.\n");
				fflush(stdout);
			}

			printf("PID: %d going into crit point %d. \n", cP, c2);
			c2++;

			MUC = sem_post(&m);

			if (MUC == -1)
			{
				perror("Memory still locked.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Memory unlocked.\n");
				fflush(stdout);
			}

			printf("PID: %d bb \n", cP);
			fflush(stdout);
		}

		else if (p3 == 0)
		{
			sleep(3);

			cP = gp();

			MLC = sem_wait(&m);

			if (MLC == -1)
			{
				perror("Shared memomy lock false.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Memory locked.\n");
				fflush(stdout);
			}

			printf("PID: %d going into boom %d. \n", cP, c3);
			c3++;

			MUC = sem_post(&m);

			if (MUC == -1)
			{
				perror("Memory not unlocked.\n");
				fflush(stdout);
				exit(1);
			}

			else
			{
				printf("Memory unlocked.\n");
				fflush(stdout);
			}

			printf("PID: %d bb\n", cP);
			fflush(stdout);
		}
	}

	MD = sem_destroy(&m);

	if (MD == -1)
	{
		perror("Semaphore destruction false.\n");
		fflush(stdout);
		exit(1);
	}

	else
	{
		printf("Semaphore destruction true.\n");
		fflush(stdout);
	}

	return 0;
}
