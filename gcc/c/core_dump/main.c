

#include <stdio.h>

int main(int argc, char** argv)
{
	char buffer[16];
	
	buffer[80000] = 3;

	return 0;
}
