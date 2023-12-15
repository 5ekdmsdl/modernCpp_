#include <iostream>

// ���� �������� ���ø� ����ϳ���?
// => �������� ���ø� ����ϴ� �������� ������ ����

// 1. �Ϻ��� ���� : ��κ� �������� ���ø� ���
// 2. std::tuple, std::get ���� �ڵ�� �������� ���ø����� ����.
// 

void foo(int a, int b, int& c) { c = 100; }

//// �Ʒ�ó�� �����, chronometry�� ���� 1��¥���� forward ����
//template<typename F, typename T>
//decltype(auto) chronometry(F f, T&& args)
//{
//	return f( std::forward<T>(arg)); 
//}

// �Ʒ�ó�� �����, chronometry�� ���� ������ forward �� ��
template<typename F, typename ...Types>
decltype(auto) chronometry(F f, Types&& ...args)
{
	//return f(std::forward<T>(arg));		// forward(E1, E2, E3)
										// forward�� ���� 1��

	return f(std::forward<Types>(args)...);
			//   f( std::forward<Types>(E1),
			//		std::forward<Types>(E2),
			//		std::forward<Types>(E3) );

}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

