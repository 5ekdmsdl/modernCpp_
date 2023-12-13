#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// (중요) 핵심 정리
//	=> 완벽한 전달 (perfect forwarding) 기술을 사용하려면
// 1. 인자를 받을때 "T&& (forwarding ref)" 로 받으셈.
// 2. 받은 인자를 다른 함수로 보낼때 "std::forward<T>(arg)" 로 묶어서 보내세요.

// 참고
// std::forward - 인자	rvalue 만을 위해 사용하기는 함.
//						lvalue 에서는 없어도 되기는 함.
// 근데 모든 경우를 고려해야하니가 꼭 "std::forward<T>(arg)" 사용!!
// (다른 방법 없다.)

template<typename F, typename T>
void chronometry(F f, T&& arg) {
	f(std::forward<T>arg);
}

int main()
{
	int n = 3;

	chronometry(foo, 10);

	chronometry(goo, n);

}
