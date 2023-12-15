// 5_SFINAE - 
#include <iostream>

template<typename T> 
void foo(T a)   { std::cout << "T" << std::endl; }

void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3);		// 1. foo(int) 사용 - exactly matching
				// 2. foo(T) - template 사용 -> foo(int) 생성
				// 3. ... (모든 걸 받을 수 있으므로)
	
	// 위처럼 동일 이름 함수 여러개
	// 함수 찾는 규칙 "overloading resolution"

}