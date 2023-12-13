// 7_완벽한전달1 - 113 page
#include <iostream>

// 완벽한 전달 하려면
// 1. 인자의 복사본 만들지 X -> call by reference
// 2. lvalue, rvalue 모두 받아야
// 3. 상수성 추가 X
// ==> int&, int&& 버전 따로 제공해야

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

template<typename F>
void chronometry(F f, int& arg)		// lvalue (n)
{
	f(arg);
}
template<typename F>
void chronometry(F f, int&& arg)	// rvalue (10)
{
	// int&& arg = 10에서
	// 10 : rvalue
	// arg : lvalue	<== 핵심 !
	f(arg);
}

int main()
{
	int n = 10;

	hoo(10);
	chronometry(hoo, 10);

	std::cout << n << std::endl;
}
