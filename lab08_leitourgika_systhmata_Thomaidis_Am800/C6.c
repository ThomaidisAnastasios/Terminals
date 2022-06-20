#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *PrintHelo(void *i)
{
  void pthread_exit(void *);
}

int main(void)
{
  int i,error;
  pthread_t threads[32000];

  for(i=0;i<32000;i++)
  {

    if(error=pthread_create(&threads[i],NULL,PrintHelo,NULL));
    {
      printf("No more pthreads[i].Thread Count %d.\n",i+1);
    }

  }

  return 0;
}
