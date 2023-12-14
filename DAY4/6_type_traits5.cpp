#include <iostream>
#include <type_traits>

// ��� ������ �����ϴ� Ÿ�� �����!
// => C++ ǥ���� �ƴϴ�!
// => C++ ǥ�ؿ��� remove_pointer �� �ֽ��ϴ�.

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = typename remove_all_pointer<T>::type;		
								// ��ͷ� �ذ�!
								// ��͸� �ص� ���� ���� X
};

int main()
{
	//remove_pointer<int***>::type n;		// ���� ������
	
	remove_all_pointer<int***>::type n;		// n�� int type!
}

