#include <iostream>

// recursion 
// 1. ��� ���ڸ� �������ڷ� ���� ����
// 2. 1��° ���ڴ� ������ ����(�̸��ִ� ����) �� ��������

// ���� : �Ʒ� �ڵ�� ��� ȣ�� X
// main => foo(����3��) => foo(����2��) => foo(����1��) => foo() ����
// => ��, ��� �ٸ� �Լ� ȣ��
//			-> ���� �ʹ� ������ �ڵ� �ʹ� Ŀ���ϱ� ���� X

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value;

	// Cpp 17 ����
	//foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()		==> �� ��츦 ���ؼ� ���ھ��� foo �ʿ�

	// Cpp 17 ����
	// if constexpr�ϸ� ���� ���� "foo()" �� �ʿ� X
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,  args : 3.4,  'A'
}





