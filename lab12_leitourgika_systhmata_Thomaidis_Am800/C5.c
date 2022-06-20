#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	struct winsize w;
	time_t ts;
	int s=0;

	time(&ts);
	s=sizeof(tm);

	printf("Time is: %s\n", ctime(&ts));
	printf("Size of time_t is: %d\n", ts);
	fflush(stdout);

	return 0;
}
