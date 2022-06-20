#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
	DIR *mydir;
	struct dirent 
	int i=50,j=50;

	mydir = opendir(".");

	while(1)
	{
		if ( readdir(mydir) == NULL )
			break;

		else
		{
			printf(%c\n", mydirent.d_name);
			printf("\e[%dC",i);
			
			printf("%c\n", mydirent.d_type);
			printf("\e[%dC",j);
				
			printf("%d\n", mydirent.d_ino);
			printf("\n");
		}

		closedir(mydir);
	}

	return 0;
}
