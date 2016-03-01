#include "stdio.h"
#include "string.h"

int main( int argc, char** test ){
	
	char str1[20] = "Samul P. Harbison";
	char str2[20];  

	printf( "Original String : %s\n", str1 ); 

	strcpy( str2, str1 );
	printf( "New String : %s\n", str2 );

	return 0;
}