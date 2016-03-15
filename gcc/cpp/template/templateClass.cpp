
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class Data
{
	T data;
public:
	Data(T d);
	void SetData(T d);
	T GetData();
};

template<typename T>
Data<T>::Data(T d)
{
	data = d;
}

template<typename T>
void Data<T>::SetData(T d)
{
	data = d;
}

template<typename T>
T Data<T>::GetData()
{
	return data;
}

int main()
{
	Data<int> d1(0);
	d1.SetData(10);

	Data<char> d2('a');
	
	cout << d1.GetData() << endl;
	cout << d2.GetData() << endl;

	return 0;
}

