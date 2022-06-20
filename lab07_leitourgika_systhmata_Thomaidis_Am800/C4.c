#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int i=0;

void cs(int signal0)
{
  extern int i;
  i=i+1;
  char j;

  sigset_t set;
  sigemptyset(&set);
  sigfillset(&set);
  sigprocmask(SIG_SETMASK ,&set ,NULL);
 
 if (i<4)
  {
    printf("You cannot kill me with Ctrl+C.\n");
    signal(signal0 ,cs);
  }
  else
  {
    signal( signal0, SIG_DFL);
    
    printf("Do you want to stop;.\n");
    scanf("%c",&j);

    switch(j)
    {
      case 'Y': case 'y':
        exit(0);
     
      default:
        i=0;   
        signal( signal0, cs);
    }
  }
  fflush(stdout);
}

void csquit(signal0_new) 
{
  i=i+1;
  char j;
  sigset_t set_new;
  sigemptyset(&set_new);
  sigfillset(&set_new);
  sigprocmask(SIG_SETMASK, &set_new, NULL);

  printf("Couner = %d" ,i );
  
  signal(signal0_new , csquit);
  fflush(stdout);
}

int main(void) 
{
  signal(SIGINT ,cs);
  signal(SIGQUIT , csquit);
  
  for ( ;; )
  {
    pause();
  }
  return 0;
}
