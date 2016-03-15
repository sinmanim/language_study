
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main( int argc, char* argv[] ){

	int a = 100;

	int &ref = a;

	cout<<"&a "<<&a<<", &ref "<<&ref<<", ref "<<ref<<endl;

	return 0;
}


