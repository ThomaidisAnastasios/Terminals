#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define Num_threads 
char *messages[NUM_THREADS];

struct thread_data
{
int thread_id;
int s;
char *message;
};

void *PrintHelo(void *i)
{
  int threadid=*(int *) i;
  printf("Hello World %d.\n",(int) (threadid+1));
  fflush(NULL);
  pthread_exit(0);
}

void *PrintHello(void *i)
{
  struct thread_data *data=i;
 

}

int main(void)
{
  int i,error,s=0;
  pthread_t threads[15];
  int* n[15];

  messages[0] = "English: Hello World!";
  messages[1] = "French: Bonjour, le monde!";
  messages[2] = "Spanish: Hola al mundo";
  messages[3] = "Klingon: NuqneH Hoch!";
  messages[4] = "German: Guten Tag, Welt!";
  messages[5] = "Russian: Zdravstvytye, mir!";
  messages[6] = "Japan: Sekai e konnichiwa!";
  messages[7] = "Latin: Orbis, te saluto!";
 
  for(i=0;i<15;i++)
  {
    n[i]=(int *)malloc(sizeof(int));
    *n[i]=i;
    s=s+1+i;
    my_array[i].s=s;
    my_array[i].msg=messages[i];    

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
