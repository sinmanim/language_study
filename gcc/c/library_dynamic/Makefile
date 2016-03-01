

simplecal : sum.o sub.o mul.o div.o 
	ar rc libseoplib.a sum.o sub.o mul.o div.o
	gcc -o simplecal $@.c -L./ -lseoplib

clean : 
	rm -f simplecal *.o *.a
