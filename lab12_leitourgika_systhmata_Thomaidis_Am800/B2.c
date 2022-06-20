#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

int c =40 ;

void sig_handler(int sig)
{
	int r;

	if (sig == SIGUSR1)
	{
		printf("Randomizing colour.\n");
		fflush(stdout);

		do
		{
			r = rand() % 40;
		}

		while(r < 30 || r > 48 );

		c = r;
	}
}

int main(int argc, char const *argv[])
{
	struct winsize w;
	time_t crntt;
	int rn, rr, rc;

	ioctl(0, TIOCGWINSZ, &w);

	signal(SIGUSR1, sig_handler);

	while(1)
	{
		printf("\e[2J");

		time(&crntt);
		srand(crntt);

		rc = rand() % (w.ws_col + 1)) - 20;  
		rr = rand() % (w.ws_row + 1); 

		printf("\e[%dm \e[%d;%df %s\n", c, rr, rc, ctime(&crntt));
		
		sleep(5);
	}

	return 0;
}
