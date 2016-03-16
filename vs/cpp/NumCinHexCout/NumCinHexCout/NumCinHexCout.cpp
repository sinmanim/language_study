
#include <iostream>

using namespace std;

int main() 
{
	int t;

	while (true)
	{
		cin.setf(ios_base::hex, ios_base::basefield);
		cin >> t;
		cout << "입력 : " << t << endl;
		if (cin.fail())
		{
			cout << "제대로 입력해주세요" << endl;
			cin.clear();	// 플래그 초기화
			cin.ignore(100, 'n');
		}
		if (t == 0) break;
	}

	return 0;
}