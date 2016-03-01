#include "stdio.h"



int main(int argc, char** test){

	char ch = 0;

	//printf( "tesN %d \n", argc);

	printf( "test %s", test[0]);

	//putchar ( 'C' );



	//while( ch != 'q' ){
	while( ch != EOF ){
		//ch = getchar();

		ch = fgetc( stdin );
		fputc( ch, stdout );
	}
	

	return 0;
}

