#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
  int var,fd1[2],fd2[2],t1=0,t2=0;
  char a1[100],a2[100],*newline;
  pid_t pid;
    
  t1=pipe(fd1);
  t2=pipe(fd2);
  
  if(t1<0)
  {
    perror("pipe1");
    exit(1);
  }
  
  if(t2<0)
  {
    perror("pipe2");
    exit(1);
  }
  
  if((pid=fork())<0)
  {
    perror("fork");
    exit(1);
  }
  
  else if(pid==0)
  {
    close(fd1[1]);
    close(fd2[0]);
    
    while(1)
    {
      var=read(fd2[0],a1,100);
      printf("Child read.$s\n",a1);
      sprintf(a1,"$s-child",a1,var);
     
      write(fd1[1],a1,(strlen(a1)+1));
    }
  }
  
  else
  {
    close(fd1[0]);
    close(fd2[1]);
    
    while(1)
    {
      printf("Type.");
      
      if(fgets(a2,100,stdin)!=NULL)
      {
	newline=strchr(a2,'\n');
        
        if(newline!=NULL)
          *newline='\0';
      }
     
      write(fd1[1],a2,(srlen(a2)+1));
      var=read(fd2[0],a1,100);
      printf("Parent read.$s\n".a1);
    }
  }

  return 0;
]
