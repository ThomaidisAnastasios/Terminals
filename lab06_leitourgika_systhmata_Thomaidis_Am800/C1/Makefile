CC= gcc
CFLAGS= -g 

all: Sp1.o Dp2.o Mp3.o Subp4.o Map0.o 
 $(CC) Map0.o Sp1.o Dp2.o Mp3.o Subp4.o -o Map0

Map0: Map0.o
 $(CC) $(CFLAGS) -c Map0.c

Sp1: Sp1.o
 $(CC) $(CFLAGS) -c Sp1.c

Dp2: Dp2.o
 $(CC) $(CFLAGS) -c Dp2.c

Mp3: Mp3.o
 $(CC) $(CFLAGS) -c Mp3.c

Subp4: Subp4.o
 $(CC) $(CFLAGS) -c Subp4.c

clean:

 rm Map0
 rm Map0.o
 rm Sp1.o
 rm Dp2.0
 rm Mp3.o
 rm Subp4.0
