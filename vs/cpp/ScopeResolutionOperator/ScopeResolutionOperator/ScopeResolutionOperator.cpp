#include <iostream>

using namespace std;

int val = 100;

int SimpleFunc(void)
{
	int val = 20;
	val += 3;	// �������� �� 3 ����
	::val += 7;	// �������� �� 7 ����

	return ::val;
}

int main()
{
	int rst = 0;
	
	rst = SimpleFunc();

	cout << "val is " << rst << endl;

	return 0;
}