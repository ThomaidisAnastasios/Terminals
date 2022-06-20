#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define Num_Threads 5

void *cthread(void *i)
{
  int i,threadid=*(int *)j;
  double r=0;
  
  printf("%d runs.\n", threadid);

  forf(i=0; i<1000000; i++)
    r=r+sin(i)*tan(i);

  printf("Thread with %d id ended.The result is %f.\n",(int) cpthread, r);
  
}

int main(void)
{
  int j,bugg;
  int* threadid(Num_Threads);
  pthread_t Threads(Num_threads);
  void *phase;

  
}
