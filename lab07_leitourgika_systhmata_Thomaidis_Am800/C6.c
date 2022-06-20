#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main(void)
{
  int child_pid;
  child_pid=fork();

  if(child_pid>0)
    printf("%d hello from child.\n",child_pid);
  else if(child_pid==0);
    printf("%d hello from parent.\n",child_pid);
  
}
