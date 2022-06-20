#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  printf("The PID is: %d\n.",getpid() );
  printf("The PPID is: %d\n.",getppid() );
  
  return 0;
}



