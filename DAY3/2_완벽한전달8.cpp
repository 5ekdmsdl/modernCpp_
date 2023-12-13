#include <iostream>

int& foo(int& a) { return a; }

//auto chronometry(F f, T&& arg) {				// auto�� ref ������ ����

// 1. ���ϰ� �Ϻ��� �����ַ��� -> decltype(auto) ���
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg) {	// decl(auto)�� ref 
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 3;

	int& ret = chronometry(foo, n);	// foo(n)

	ret = 200;

	std::cout << n << std::endl;
	
}
