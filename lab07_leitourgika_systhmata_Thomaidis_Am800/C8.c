#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
  int i=-2,j=-2,wi,wj,x,y;
  int status;
  i=fork();

  if(i<0)
  {
    printf("Error.\n");
    exit(1);
  }
  
  j=fork();
  
  if(j<0)
  { 
    printf("Error.\n");
    exit(1);
  }
  
  if(i!=0 && j!=0)
  {
    wi=wait(&status);
    
    if(wi==i)
      printf("The command wait was used from the first process.\n");
    
    if(wj==j)
      printf("The command wait was used from the second process.\n");

    wj=wait(&status);
    
    if(wi==i)
      printf("The command wait was used from the first process.\n");

    if(wj==j)
      printf("The command wait was used from the second process.\n");
  }

  if(i==0)
  {
    srand(0);
    x=((rand() %10)+3);
    sleep(x);
    exit(2);
  }
  
  if(j==0)
  {
    srand(20);
    y=((rand() %10)+3);
    sleep(y);
    exit(2);
  } 
  
  return 0;
}
