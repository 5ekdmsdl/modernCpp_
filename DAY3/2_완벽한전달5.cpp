#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
/*
template<typename F>
void chronometry(F f, int& arg)
{
	//f(arg);					// A
	f(static_cast<int&>(arg));	// B : �ʿ���� ĳ���������� ���� ���� X 
								// (������ �ð��� ����)
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

template<typename F, typename T>
void chronometry(F f, T&& arg) {
	f(static_cast<T&&>(arg));
}

// �ᱹ int&, int&& ������ �ʿ��ϰ�, int �Ӹ��ƴ϶� �ٸ� Ÿ�Ե� �����ؾ�
// T&& ����ϸ� �� 2�� �ڵ����� (int �Ӹ� �ƴ϶� ��� Ÿ�Կ���)
// but, ���ø����� �Լ� �ڵ������Ϸ��� �Լ��� ������ ���ƾ�!

int main()
{
	int n = 3;
	// �����Ǵ� �Լ� ��� & ĳ���� �ڵ� �����ϱ� (�߿�)
	chronometry(foo, 10);
			// 10:rval, T:int, chro(F f, int&&)
			// static_cast<int&&>(arg) -> int&& (rval)
	chronometry(goo, n);
			// n :lval, T:int&, chro(int&)
			// static_cast<int&>(arg) -> int& (lval)
}
