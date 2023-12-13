#include <string>
#include <iostream>

int main()
{
	// std::move : 단지 rvalue 로 캐스팅 할 뿐입니다.
	//			   이동생성자가 있는 타입만 효과가 있습니다

	// #1
	std::string s1 = "aaaaaa";
	std::string s2 = std::move(s1);
		// string은 move 생성자 제공
		// => 자원 이동

	// #2.
	int n1 = 10;
	int n2 = std::move(n1);		// n1 = 0 ??
				// => 아니고 그냥 rvalue casting이다.
	
	// #3.
	int* p1 = new int;
	int* p2 = std::move(p1); // 이 코드는
	//int* p2 = p1;			 // 이 코드와 동일

	// #4. swap에 대해서
	std::string s3 = "aaa";
	std::string s4 = "ccc";

	std::swap(s3, s4);	// Cpp98 시절의 swap
						// 버퍼 자체 복사 -> 느리다.
				// Cpp11 이후 : move 생성자를 이용한 swap
				// 아래 멤버함수 swap이랑 똑같음.

	s3.swap(s4);	// s3의 버퍼 주소와 s4의 버퍼 주소를 swap = pointer swap







}