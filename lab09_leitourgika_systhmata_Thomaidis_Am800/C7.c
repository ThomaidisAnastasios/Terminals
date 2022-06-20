#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main(void)
{
  int child,parent;
  child=fork();

  if(child==0)
  printf("I am the mother with PID %d and with daughter process %d.\n",getppid(),getpid());
  
  parent=fork();

  if(parent==0)
  printf("I am the father with PID %d, and my daughter process is %d.\n",getpid(),getppid());
}
