#include <iostream>

// #1. �迭 ������ -> T = �迭 ������   (int*)
template<typename T> void foo(T a)
{
	std::cout << __FUNCSIG__ << std::endl;
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// #2. �迭 ���� -> T = �迭 (������ X) (int[3])
template<typename T> void goo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };
	
	// x�� Ÿ�� : int[3]
	// �ٵ� T == int[3] ��� ���� �Ұ���
	foo(x); // ���� T �� int[3] �� �����ϸ�
			// int a[3] = x; �� �˴ϴ�. �迭�� ���簡 �ȵǹǷ� ������ ����!!
			// int* a = x;   �� �����ߴٸ� ok.

	goo(x); // T = int[3]�̸� 
			// int(&a)[3] = x;
			// �迭 ����Ű�� ������ ���� X
}