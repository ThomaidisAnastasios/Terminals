#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)

{
	struct winsize w;
	int i=0, st=1;

	printf("[..........]\e[11D");
	fflush(stdout);

	for (i = 0; i < 10; i++)
	{
		printf(" \e[31m* ");
		sleep(st);
		fflush(NULL);
	}

	printf("\e[0m\n");

	return 0;
}
