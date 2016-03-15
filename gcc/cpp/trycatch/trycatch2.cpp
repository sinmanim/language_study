
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Data
{
	int num;
public:
	Data();
	Data(int _num);
	void ShowNum();
};

Data::Data(int _num)
{
	this->num = _num;
}

void Data::ShowNum()
{
	cout << "num is => " << num << endl;
}

int main()
{
	int inNum;

	//Data d1(3);
	//d1.ShowNum();

	cout << "input : ";
	cin >> inNum;

	try{
		if(inNum>0)
			throw inNum;
		else
			throw 'm';
	}
	catch(int exp){
		cout << "int exception " << inNum << endl;
	}
	catch(...){
		cout << "Undefined exception " << endl;
	}

	return 0;
}

