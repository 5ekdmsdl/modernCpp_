#include <iostream>
#include <type_traits>

// ���� �ִ� ����� ���ϴ� �Լ�
// �ִ� ������� �������� �����ؾ�
template<typename T> T gcd(T a, T b)
{
	// ��� 1: static_assert
	// => static_assert�� ���� ���� X -> error
	// => ���� ���� ���ص� 
	// �ĺ������� ���ܵǴ°� ���� ������.
	static_assert(std::is_integral_v<T>, "error, not integral");

	return 0;
}

void gcd(double a, double b) {  }

int main()
{
	gcd(6, 9);			// T->int ���� ���
	gcd(3.1,  5.4);		// double ���� ���
	gcd(3.1f,  5.4f);	// T->float ���� ��� -> assert fail




	
}