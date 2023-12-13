// 9_�Ϻ�������_���ǻ���
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0; �ް� �Ǹ� f(arg) error
{								// int ���� -> Point casting X
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok
	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // good!

	// �Ϻ� ���� == ���ø��̱� ������ 
	// 0 �� int�� �ν�
	// ���� ���� �޴� �Լ� ���� �������϶�, 0 ���� ������ error 
	// => 0 ���� nullptr ���!
}

