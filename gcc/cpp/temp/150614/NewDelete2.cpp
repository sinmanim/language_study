
#include<iostream>
#include<string.h>

using std::cout;
using std::cin;
using std::endl;

char* MakeStrAdr(int len);

int main(int argc, char* argv[]){

	char* str=MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	// free(str);
	delete []str;
	
	return 0;
}


char* MakeStrAdr(int len){

	// char* str = (char*)malloc(sizeof(char)*len);
	char* str=new char[len];
	return str;
}







