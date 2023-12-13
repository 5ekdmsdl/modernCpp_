#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// (�߿�) �ٽ� ����
//	=> �Ϻ��� ���� (perfect forwarding) ����� ����Ϸ���
// 1. ���ڸ� ������ "T&& (forwarding ref)" �� ������.
// 2. ���� ���ڸ� �ٸ� �Լ��� ������ "std::forward<T>(arg)" �� ��� ��������.

// ����
// std::forward - ����	rvalue ���� ���� ����ϱ�� ��.
//						lvalue ������ ��� �Ǳ�� ��.
// �ٵ� ��� ��츦 ����ؾ��ϴϰ� �� "std::forward<T>(arg)" ���!!
// (�ٸ� ��� ����.)

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
