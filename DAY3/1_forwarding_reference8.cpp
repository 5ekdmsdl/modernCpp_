#include <iostream>

template<typename T> void foo(T&& arg)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;

	// �Ʒ� �ּ� �ܿ����Ѵ�. (���蹮��)
	foo(n);  // T=int&, T&&=int&,	foo(int&)
	foo(10); // T=int,	T&&=int&&,	foo(int&&)
}



