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
	long mt;
	char t[S];
};

int main(int argc, char const *argv[])
{
	key_t k = 709;
	int ide, loop = 0, sendcheck;

	struct queuery send_buffer;

	ide= msgget(key, 0666);

	if (ide == -1)
	{
		printf("Error.\n");
		fflush(stdout);
		exit(1);
	}
	else if (ide!= -1)
	{
		printf("Creation true. Identifier: %d.\n",ide);
		fflush(stdout);
	}

	while (loop < 3)
	{
		send_buffer.mtype = 0;
		printf("User message:... \n");
		fflush(stdout);
		fgets(send_buffer.mt, 255, stdin);
		printf("Sending %d Bytes. \n",strlen(send_buffer.mtext));

		check = msgsnd(ide, &send_buffer, S, MSG_NOERROR);

		if (check == -1)
		{
			printf("Error at sendind the message. \n");
			fflush(stdout);
			exit(1);
		}
		else if (check == 0)
		{
			printf("Message send succesfully. \n");
			fflush(stdout);
		}

		loop++;
	}

	return 0;
}
