#include <iostream>

// template 타입 추론 규칙 
// 1. 인자의 타입이 "값(value)" 일때
// => 인자가 가지고 있는 "const, volatile, reference" 의 속성을 제거후
// 타입결정
template<typename T> void foo(T a)
{
	//	a = 100;
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);		// T = int 
	foo(c);		// T = int
	foo(r);     // T = int
	foo(cr);    // T = int

	// 인자를 가신 const 속성만 제거
	const char* s1 = "hello";

	foo(s1);

	const char* const s2 = "hello";
	foo(s2); // s2 const, 가르키는 곳도 const
	// s2 = const char* const
	// T => const char*
}