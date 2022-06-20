#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
  pid_t pid;
  pid=fork();
  
  if(pid==0)
  {
    printf("%d.Child will now exit and create zombie.\n",getpid());
    exit(0);
  }
  
  else
  {
    printf("Parent ps xuw.\n");
    system("ps xuw");
    sleep(10);
  }
  
  return 0; 
}
