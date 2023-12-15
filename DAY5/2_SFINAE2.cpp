#include <iostream>


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	// 어떤 함수 사용할지는 "함수 인자"만 보고 판단
	foo(3);		// 1. 컴파일러는 T 사용하기로 결정
				// 2, T=int로 결정 -> 함수 생성
				// 3. 함수 생성시 리턴 타입이 "int::type" 이되므로 함수 생성실패
			// => 이때 "에러" 가 아니라 후보군에서 제외되고
			//    foo(...) 을 사용하게 됩니다.

	// Substitution Failure Is Not An Error
	// => 치환 실패는 에러가 아니다.
	// => SFINAE
}