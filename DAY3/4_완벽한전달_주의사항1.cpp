// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0; 받게 되면 f(arg) error
{								// int 변수 -> Point casting X
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok
	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // good!

	// 완벽 전달 == 템플릿이기 때문에 
	// 0 은 int로 인식
	// 최종 전달 받는 함수 인자 포인터일때, 0 쓰면 무조건 error 
	// => 0 말고 nullptr 써라!
}

