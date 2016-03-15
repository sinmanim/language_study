

#include<iostream>

using namespace std;

template <typename T>
T Add(T num1, T num2)
{
	cout<<"T Add(T num1, T num2)"<<endl;
	return num1+num2;
}

int Add(int num1, int num2)
{
	cout<<"Add(int num1, int num2)"<<endl;
	return num1+num2;
}

double Add(double num1, double num2)
{
	cout<<"Add(double num1, double num2)"<<endl;
	return num1+num2;
}

template <class T1, class T2>
void ShowData(double num)
{
	cout<<(T1)num<<", "<<(T2)num<<endl;
}

int main(int argc, char** argv)
{
	cout<< Add(5, 7) 					<<endl;
	cout<< Add(3.7, 7.5)				<<endl;
	cout<< Add<int>(5, 7)			<<endl;
	cout<< Add<double>(3.7, 7.5)  <<endl;

	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(69.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);

	return 0;
}


