#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
  int i,j[2];
  i=pipe(j);
  char buffer[200];

  if(i==-1)
  {
    printf("Error.Pipe wasnt created.\n");
  }
  
  else
  {
    write(j[1],"Thomaidis Anastasios",30);
    read(j[0],buffer,sizeof(buffer));
    printf("%s\n",buffer);
  }
  
}
