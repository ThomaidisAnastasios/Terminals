#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define S 255

struct queuery
{
	long mty;
	char mt[S];
};

int main(int argc, char const *argv[])
{
	key_t k = 709;
	int ide, loop = 0,check;

	struct queuery receive_buffer;

	ide = msgget(key, 0666 | IPC_CREAT | IPC_NOWAIT);

	if (ide == -1)
	{
		printf("Error at creating mailbox. \n");
		fflush(stdout);
		exit(1);
	}
	else if (identifier != -1)
	{
		printf("Creation true. Identifier: %d. \n",ide);
		fflush(stdout);
	}

	while (loop < 3)
	{
		sleep(1);
		check = msgrcv(ide, &receive_buffer, SIZE, 0, MSG_NOERROR);

		if (check == -1)
		{
			printf("No message. Sleeping... \n");
			fflush(stdout);
		}
		else
		{
			printf("New message: %s \n",receive_buffer.mt);
			fflush(stdout);
		}

		loop++;
	}

	msgctl(ide, IPC_RMID, (struct msqid_ds *) 0);

	return 0;
}
