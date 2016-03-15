
#include <iostream>
#include <cstring>

using namespace std;

class Test 
{
	int testNum;
	char testName[20];

public:
	Test()
	{
		testNum = 0;
		strncpy(testName, "testSeop", strlen("testSeop"));
	}
	Test(const char* name);

	char* getClassName();
};

Test::Test(const char* name)
{
	testNum = 1;
	strncpy(testName, name, strlen(name));
}


char* Test::getClassName()
{
	return testName;
}

int main()
{
	Test* testArray[10];

	testArray[0] = new Test();

	testArray[1] = new Test("testClass");

	cout << "Test Class 1 name is " << testArray[0]->getClassName() << endl;
	cout << "Test Class 2 name is " << testArray[1]->getClassName() << endl;

	delete testArray[0];
	delete testArray[1];

	return 0;
}
