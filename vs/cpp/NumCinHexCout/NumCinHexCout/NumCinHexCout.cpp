
#include <iostream>

using namespace std;

int main() 
{
	int t;

	while (true)
	{
		cin.setf(ios_base::hex, ios_base::basefield);
		cin >> t;
		cout << "�Է� : " << t << endl;
		if (cin.fail())
		{
			cout << "����� �Է����ּ���" << endl;
			cin.clear();	// �÷��� �ʱ�ȭ
			cin.ignore(100, 'n');
		}
		if (t == 0) break;
	}

	return 0;
}