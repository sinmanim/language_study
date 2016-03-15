
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num;
		
	cout << "input number: ";
	cin >> num;

	try{
		if(num >0)
			throw 10;
		else
			throw 'm';
	}
	catch(int exp){
		cout << "int exception" << endl;
	}
	catch(char exp){
		cout << "char exception" << endl;
	}

	return 0;
}

	
