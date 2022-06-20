#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *PrintHelo(void *i)
{
  int threadid=*(int *) i;
  printf("Hello World %d.\n",(int) (threadid+1));
  fflush(NULL);
  pthread_exit(0);
}

int main(void)
{
  int i,error;
  pthread_t threads[15];
  int* n[15];
 
  for(i=0;i<15;i++)
  {
    n[i]=(int *)malloc(sizeof(int));
    *n[i]=i;
    
    if(error=pthread_create(&threads[i],NULL,PrintHelo,(void *)n[i]))
    {
      printf("Error.\n");
      exit(1);
    }

  }
 
  for(i=0;i<15;i++)
  {
    pthread_join(threads[i],NULL);
  }

  return 0;
}
