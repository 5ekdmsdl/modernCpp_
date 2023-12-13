#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;		// string 복사 생성자 호출
								// 깊은 복사로 구현
								// 문자열 자체를 복사
	std::string s4 = std::move(s2);	
								// s2의 문자열 자원 s4로 이동
								// s2는 더이상 문자열 자원 X
								// s4 자원은 s2가 가져감

	std::cout << s1 << std::endl;	// "hello"
	std::cout << s2 << std::endl;	// ""


}

