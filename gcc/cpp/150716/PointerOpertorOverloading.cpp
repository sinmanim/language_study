

#include<iostream>

using namespace std;

class Number
{
private :
	int num;
public :
	Number(int n) : num(n) { }
	void ShowData() { cout<<num<<endl; }

	Number * operator->()
	{
		return this;
	}

	Number& operator*()
	{
		return *this;
	}
};

int main(int argc, char** argv)
{
	Number tnum(20);
	tnum.ShowData();

	(*tnum)=30;
	tnum->ShowData();
	(*tnum).ShowData();
	
	return 0;
}

