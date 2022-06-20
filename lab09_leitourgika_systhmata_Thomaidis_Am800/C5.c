#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

int main(void)
{
  int i=0,j,fildes[2];
  char b0[200],b1[200];
  pid_t pid;
  pid=fork();
  j=pipe(fildes);
  
  if(pid==0)
  {
    close(fildes[1]);
    
    while(1)
    {
      sleep(1);
      read(fildes[0],b0,200);
      printf("Child read:%s\n",b0);
      
      if(!strcmp(b0,"00"))
      {
	kill(getpid(),SIGINT);
        exit(0);
      }
    }
  }
  
  else
  {
    close(fildes[0]);
   
    while(1)
    {
      sleep(1);
      printf("Type.\n");
      
      if(fgets(b1,200,stdin)!=NULL)
      {
        char *line=strchr(b1,'\n');
        
        if(line!=NULL)
        {
          *line='\0';
        }
      }
      
      write(fildes[1],b1,5);
    }
  }

return 0;
 
}
