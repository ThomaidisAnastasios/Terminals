#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *helloworld (void *arg)
{
  printf("Hello World from Thread.\n");
  pthread_exit(0);
}

int main(void)
{
  int i,j;
  
  printf("Give the number of threads.\n");
  scanf("%d",&i);
  
  pthread_t threads[i];
  
  for(j=0;j<i;j++)
  {
    printf("Threads %d.\n",j+1);
    pthread_create(&threads[j],NULL,helloworld,NULL);
  }

}
