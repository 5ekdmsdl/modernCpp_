#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// => args�� �ִ� 2��° ��� ������ �ʹ�.	=> �ѹ����� x

	// #1. �Ʒ� ��� �� �Ѱ��� ����ؾ�
	//		1. pack expansion			- Cpp 11
	//		2. recursion ���� �ڵ�		- Cpp 11
	//		3. fold expression			- Cpp 17

	// # pack expansion
	// ��� ��Ұ� ���� Ÿ�� ���� ������ �迭 ���
	int x[] = { args... };

	// Ÿ�� �ٸ��� tuple�� ���
	std::tuple<Types...> t = { args... };
}


int main()
{
	foo(1, 2, 3);
}

