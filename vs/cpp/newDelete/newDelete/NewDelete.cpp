#include <iostream>
#include <cstring>

#define cout ::std::cout
#define endl ::std::endl


char *MakeStrAdr(int len)
{
	char *str = new char[len];
	return str;
}

int main()
{
	char *str = MakeStrAdr(20);
	strcpy_s(str, strlen("I am so Happy~~")+1, "I am so Happy~~");
	cout << str << endl;
	delete[] str;
	return 0;
}