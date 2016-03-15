
#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

template<typename T>
int SizeOf(T a)
{
	return sizeof(a);
}

template<>
int SizeOf(char* a)
{
	return strlen(a);
}

int main()
{
	int i=0;
	double e=7.7;
	char* str;
	strcpy(str, "Hello world~!");

	cout << SizeOf(i) << endl;
	cout << SizeOf(e) << endl;
	cout << SizeOf(str) << endl;

	return 0;
}
