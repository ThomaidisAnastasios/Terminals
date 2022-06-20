#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/uio.h>

int main(void)
{
  int sv[2];
  int i=socketpair(PF_UNIX,SOCK_STREAM,SOCK_STREAM,sv);
  char buffer[200];
   
  if(i==-1)
  {
    perror("Socketpair.\n");
    exit(0);
  }
  
  else
  {
    char mfn[]="Anastasios";
    write(sv[1],mfn,(strlen(mfn)+1));
    read(sv[0],buffer,200);
    
    printf("My name is %s.\n",buffer);
    char mln[]="Thomaidis";
    
    write(sv[1],mln,(strlen(mln)+1));
    read(sv[0],buffer,200);
    
    printf("My last name is %s\n",buffer);
  }
  return 0;
}
