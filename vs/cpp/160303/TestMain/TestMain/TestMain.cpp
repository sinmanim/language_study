
#include <iostream>

using namespace std;

class Test 
{
	int testNum=0;
	char testName[20] = "testClass";

public:
	Test();

	char* getClassName();
};

Test::Test()
{
	strcpy_s(testName, strlen("testSeop"), "testSeop");
}

char* Test::getClassName()
{
	return (&testName[0]);
}

void main()
{
	Test* testArray[10];

	testArray[0] = new Test();

	cout << "Test Class name is " << testArray[0]->getClassName() << endl;

	delete testArray[0];
}