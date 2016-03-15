
#include<iostream>

using namespace std;

namespace BestComImple
{
		void SimpleFunc();
}

namespace ProgComImple
{
	void SimpleFunc();
}

int main(int agrc, char* argv[]){

	BestComImple::SimpleFunc();
	ProgComImple::SimpleFunc();
	return 0;
}

void BestComImple::SimpleFunc(){
	cout<<"BestCom이 정의한 함수"<<endl;
}

void ProgComImple::SimpleFunc(){
	cout<<"ProgCom이 정의한 함수"<<endl;
}


