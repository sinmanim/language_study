#include <iostream>

using namespace std;

int val = 100;

int SimpleFunc(void)
{
	int val = 20;
	val += 3;	// 지역변수 값 3 증가
	::val += 7;	// 전역변수 값 7 증가

	return ::val;
}

int main()
{
	int rst = 0;
	
	rst = SimpleFunc();

	cout << "val is " << rst << endl;

	return 0;
}