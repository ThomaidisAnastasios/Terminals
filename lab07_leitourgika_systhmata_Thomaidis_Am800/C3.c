#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void cs()
{
  printf("You cannot kill me with Ctrl+C.\n");
  signal(SIGINT, catch_sigint);


int main(void)
{
  char i;
  int j=0;
  pid_t PID0;

  PID0 = getpid();

  printf("The PID is: %d\n.",getpid() );
  printf("The PPID is: %d\n.",getppid() );

  printf("Would you like to use a function of signal handling?\n");
  scanf("%c",&i);
  
  for ( ;; )
  { 
   switch(i)
   {
    if( (i=Y) || (i=y) )
    {
      j=1;
      signal(SIGINT,cs);
      for ( ;; )
      pause();
    }
    else if( (i=N) || (i=n) )
    {
      j=1;
      for ( ;; )
      pause();
    }  
    else
    {
      printf("Would you like to use a function of signal handling?\n");
      scanf("%c",&i);   
    }
   }
   if( j==0 )
   break;
  }
  return 0;
}
