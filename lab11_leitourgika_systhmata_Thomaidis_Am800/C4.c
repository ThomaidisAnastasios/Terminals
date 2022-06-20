#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	char fn[50], bR[200], bW[200];
	int fs;

	struct stat fs1;

	if (argc == 0)
	{
		printf("Error. No parameter at input. \n");
		fflush(stdout);
		exit(1);
	}

	else if (argc == 1)
	{
		fflush(stdout);
	}

	printf("Give the name of the file.\n");
	fflush(stdout);
	fgets(fn, 50, stdin);
	fflush(stdin);
	printf("Name%s.\n",fn);
	fflush(stdout);

	fs = stat(fn, &fs1);

	if (fs == -1)
	{
		perror("Error.\n");
		fflush(stdout);
		exit(1);
	}

	else if (fs == 0)
	{
		printf("Something exists.\n");
		fflush(stdout);
	}

	return 0;
}
