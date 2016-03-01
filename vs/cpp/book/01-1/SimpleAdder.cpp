 #include <iostream>
 #include <locale>
 
 int main( void ) {
	 
	std::setlocale(LC_ALL, "korean");
	 
	 int val1;
	 // std::cout<<"첫 번째 숫자입력: ";
	 // wcout << "첫 번째 숫자입력: " << uni << endl;
	 wcout << "첫 번째 숫자입력: " ;
	 std::cin>>val1;
	 
	 int val2;
	 // wcout << "두 번째 숫자입력: " << uni << endl;
	 std::cout<<"두 번째 숫자입력: ";
	 std::cin>>val2;
		 
	 int result = val1 + val2;
	 std::cout<<"덧셈결과: "<<result<<std::endl;
	 
	 return 0;
 }