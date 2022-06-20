#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

void *nothing ()
{
  int i=0;

  i=i+1;
  pthread_exit(0);
}

int main(void)
{
  int i=0;
  time_t s,e;
  pthread_t T[1000];
 
 time(&s);

  printf("Staring amount of seconds %d.\n",(int) s);

  while(i<1000)
  {
    pthread_create(&T[i],NULL,nothing,NULL);
  }

  i=0;

  while(i<1000)
  {
    pthread_join(T[i],(void*)NULL);
    i++;
  }

  time(&e);

  printf("The final amount of seconds is %d.\n",(int) e);
  printf("e-s %d\n",(int) (e-s));
  printf("The average %f\n",(float) ((e-s)/1000));

  return 0;
}
