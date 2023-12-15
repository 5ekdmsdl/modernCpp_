#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	printv(args...);		// error, printv(1, 2, 3)�� �ǹ� 

	printv(args)...;		// printv(1), printv(2), printv(3)�� �ǹ� 
							// �ٵ� error
							// pack expansion �� �� X
	
	// #1. pack expansion �Ʒ� ��ġ������ ����
	// 1. �Լ� ȣ���� () ��			: goo(args...)
	// 2. ���ø� ������ <> ��		: std::tuples<Types...>
	// 3. {} �ʱ�ȭ ���			: int x[] = {args...};
	
	// args �� ��� ��Ҹ�  printv �� ��������
	// => �Ʒ� ����� Cpp 11 ó�� �������� ����ߴ� �ڵ�
	// => ������ �� ���� ��� ���� (fold expression)
	int x[] = { 0, (printv(args) , 0)... };
		//	{ 0, (printv(1), 0) , (printv(2), 0), (printv(3), 0) }


}


int main()
{
	foo(1, 2, 3);
}

