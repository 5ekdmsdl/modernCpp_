#include <iostream>

template<typename T> void foo(T a, T b)
{
}

template<typename T> void goo(T& a, T& b)
{
}


int main()
{
	// "banana" : const char[7]
	// "apple" : const char[6]

	foo("banana", "apple");
	// const char[7] => const char*
	// const char[6] => const char*
	// => T�� �Ȱ��� -> error X

	//goo("banana", "apple");		// error
	// const char[7] => const char[7]
	// const char[6] => const char[6]
	// �迭 ������ ������ �迭�� �ް� ��
	// T�� 2���� �ٸ� Ÿ������ deduction��.
}