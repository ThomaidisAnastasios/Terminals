#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(void)
{
  int i,status;
  pid_t parent,child;
  child=fork();
  
  if(child==0)
  {
    File*file;
    
    for(i=0;i<10;i++)
    {
      file=fopen("File0.tmp","Ok");
      fprintf(file,"%d",i);
      fclose(file);
      sleep(1);
    }
    exit(0);
  }
  
  parent=fork();
  
  if(parent==0)
    execl("/usr/bin/tail","File0.txt",(char  *) 0);
  else
  {
    wait(&status);
    kill(parent,SIGSTOP);
    fflush(stdout);
  }
 
   return 0;
}
