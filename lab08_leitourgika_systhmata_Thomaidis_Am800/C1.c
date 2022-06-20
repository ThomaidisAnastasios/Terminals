#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

void nothing() 
{
  int x=0;
  x=x+1;
}

int main(void)
{
  time_t s,e;
  pid_t P(100);
  int status(100),i=0;
  
  s=time(NULL);
  printf("Starting amount of seconds %d:\n", (int) s);

  while(i<100)
  {
    if((P(i)=fork())==-1)
    {
      printf("Failor.\n");
      exit(1);
    }
    
    if(P(i)==0)
    {
      nothing();
      exit(1);
    }
    i++;
  }
  i=0;

  while(i<100)
  {
    waitpid(P(i),&status(i),WNOHANG);
    i++;
  }
  
  e=time(NULL);
  
   printf("The final amount of seconds %d:\n",(int) e);
   printf("end - start %d\n",(int) (e-s));
   printf("The average amount %f:\n",(float)((e-s)/100));
   
   return 0;
}
