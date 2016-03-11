#include <iostream>
#include <cstring>
#include <cstdlib>

char *MakeStrAdr(int len)
{
	char *str = (char *)malloc(sizeof(char)*len);
	return str;
}

int main()
{
	char *str = MakeStrAdr(20);
	strcpy_s(str, strlen("I am so Happy~")+1, "I am so Happy~");
	::std::cout << str << ::std::endl;
	free(str);
	return 0;
}
