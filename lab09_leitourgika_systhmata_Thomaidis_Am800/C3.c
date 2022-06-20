#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
  int i=0,j,fildes[2];
  
  j=pipe(fildes);
  
  for(;;)
  { 
    write(fildes[i],"i",1);
    i=i+1;
    printf("Number=%d.\n",i);
  }

return 0;
}
