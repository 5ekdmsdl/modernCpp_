// 4_type_traits3 - 210 page
#include <iostream>

// 표준  traits 를 사용하려면
#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. 조사하려면
	bool b1 = std::is_pointer<T>::value;	// Cpp 11 스타일
	bool b2 = std::is_pointer_v<T>;			// Cpp 17 스타일

	// 2.1 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1;	// Cpp 11 스타일
	remove_pointer_t<T>::type_info n2;			// Cpp 14 스타일
}

int main()
{
	int n = 0;
	foo(&n);
}

// Cpp 14에서 remove_pointer 등을 쉽게 사용하기 위한 alias 제공
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;
