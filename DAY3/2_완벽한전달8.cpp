#include <iostream>

int& foo(int& a) { return a; }

//auto chronometry(F f, T&& arg) {				// auto는 ref 버리고 결정

// 1. 리턴값 완벽히 돌려주려면 -> decltype(auto) 사용
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg) {	// decl(auto)는 ref 
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 3;

	int& ret = chronometry(foo, n);	// foo(n)

	ret = 200;

	std::cout << n << std::endl;
	
}
