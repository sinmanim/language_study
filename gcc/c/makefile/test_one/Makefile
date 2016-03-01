
CC=gcc
CFLAGS=-I.
DEPS=hellomake.h

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake : hellomake.c hellofunc.c
# gcc -o hellomake hellomake.c hellofunc.c -I.
#	$(CC) -o hellomake hellomake.c hellofunc.c -I. 

hellomake : hellomake.o hellofunc.o
	gcc -o hellomake hellomake.o hellofunc.o -I.

clean : 
	rm -f hellomake 
	rm -f *.o
