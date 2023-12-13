// 7_�Ϻ�������1 - 113 page
#include <iostream>

// �Ϻ��� ���� �Ϸ���
// 1. ������ ���纻 ������ X -> call by reference
// 2. lvalue, rvalue ��� �޾ƾ�
// 3. ����� �߰� X
// ==> int&, int&& ���� ���� �����ؾ�

void foo(int a) {}
void goo(int& a) { a = 100; }

template<typename F>
void chronometry(F f, int& arg)		// lvalue (n)
{
	f(arg);
}
template<typename F>
void chronometry(F f, int&& arg)	// rvalue (10)
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10);

	chronometry(goo, n);

	std::cout << n << std::endl;
}
