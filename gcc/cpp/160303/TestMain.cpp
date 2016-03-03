
#include <iostream>
#include <cstring>

using namespace std;

class Test 
{
	int testNum;
	char *testName;

public:
	Test()
	{
		testNum = 0;
		testName = "testSeop";
	}

	char* getClassName();
};

char* Test::getClassName()
{
	return testName;
}

int main()
{
	Test* testArray[10];

	testArray[0] = new Test();

	cout << "Test Class name is " << testArray[0]->getClassName() << endl;

	delete testArray[0];

	return 0;
}
