#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
  pid_t PID0;
  PID0 = getpid();

  printf("The PID is: %d\n.",getpid() );
  printf("The PPID is: %d\n.",getppid() );
  
  kill(PID0, SIGSTOP); 

  return 0;
}



