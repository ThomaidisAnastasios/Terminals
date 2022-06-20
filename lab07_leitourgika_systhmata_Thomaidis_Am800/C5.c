#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

void signal0(int signal0)
{
  exit(0);
}

int main(void)
{
  int i;
  char j;
  signal(SIGALRM, signal0);

  for( ;; ) 
  {
    printf("You wish to show the PID?\n");
    scanf("%c",&j);

    switch(j)
    {
      case "Y": case "y":
        alarm(0);
	printf("PID=%d \n", getpid());
	exit(0);

      case "N": case "n":
	i=alarm(0);
	printf("There are %d seconds remaining.\n", i);
	exit(0);

      default:
        alarm(10);
        printf("You wish to show the PID?\n");
	scanf("%c",&j);
    }
  }
}

    

