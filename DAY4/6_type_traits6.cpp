// 4_type_traits3 - 210 page
#include <iostream>

// ǥ��  traits �� ����Ϸ���
#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. �����Ϸ���
	bool b1 = std::is_pointer<T>::value;	// Cpp 11 ��Ÿ��
	bool b2 = std::is_pointer_v<T>;			// Cpp 17 ��Ÿ��

	// 2.1 ���� Ÿ���� ��������
	typename std::remove_pointer<T>::type n1;	// Cpp 11 ��Ÿ��
	remove_pointer_t<T>::type_info n2;			// Cpp 14 ��Ÿ��
}

int main()
{
	int n = 0;
	foo(&n);
}

// Cpp 14���� remove_pointer ���� ���� ����ϱ� ���� alias ����
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;
