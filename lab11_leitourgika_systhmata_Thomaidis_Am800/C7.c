#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
    char *n0,*n1;
    int i;

    n1=basename(argv[0]);

    printf("Name n0=%s.\n",n0);

    n0=strcat(n0,".IIIIII");

    i=mkstemp(n0);

    if(i==-1)
        perror("mkstemp");

    n1="Yolo";

    if(write(i,n1,strlen(n0)+1)==-1)
        perror("Writing a novel.");

    if(close(i)==-1)
        perror("Boom!");

    sleep(15);

    if(unlink(n0)==-1)
        perror("unlink");

    printf("The descriptor died from the explosion.");

    return 0;
}
