#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
  int i,j=0,fildes[2];

  for(;;)
  {
    i=pipe(fildes);
    
    if(i==-1)
    {
      perror("Error");
      printf("Error.:%d.\n",i);
      exit(0);
    }
    
    else 
    {
      j=j+1;
      printf("Number=%d.\n",j);
    }
  }

return 0;
}
