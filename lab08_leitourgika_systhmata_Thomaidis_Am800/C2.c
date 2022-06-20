#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
main ()
{pid_t p;
if (p=vfork()==0)
{ puts("I am the child");}
else { puts("I am the parent");}
puts("End");
_exit(0);
}

