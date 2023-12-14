#include <iostream>
#include <type_traits>

// 모든 포인터 제거하는 타입 만들기!
// => C++ 표준은 아니다!
// => C++ 표준에는 remove_pointer 만 있습니다.

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = typename remove_all_pointer<T>::type;		
								// 재귀로 해결!
								// 재귀를 해도 성능 저하 X
};

int main()
{
	//remove_pointer<int***>::type n;		// 이중 포인터
	
	remove_all_pointer<int***>::type n;		// n은 int type!
}

