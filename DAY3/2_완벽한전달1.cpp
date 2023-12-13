// 7_�Ϻ�������1 - 113 page
#include <iostream>

// foo, goo �� �پ��� �Լ��� ����(����ð�)�� �����ϰ� �ʹ�.

void foo(int a) {}
void goo(int& a) { a = 100; }

// forwarding : ���� ���� ���ڸ� �ٸ� �Լ��� �ٽ� ����
// perfect forwarding 
// : �����Ҷ�, ��� ��ȭ�� ���� ���� �״�� ���� ���


// Ư�� �Լ��� ����(����ð�)�� �����ϴ� �Լ�
template<typename F, typename T>
void chronometry(F f, const T& arg)	// �̷��� �ص� �Ϻ� ���� X
{
	// =========> ���⼭ �ð� ������ ����
	f(arg);	   // �Լ��� ȣ��
	// =========> ���⼭ �ٽ� �ð��� ������ ����ð� ���
}

int main()
{
	int n = 10;

	chronometry(foo, 10);

	chronometry(goo, n);

	std::cout << n << std::endl;
}
