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
	// => T가 똑같다 -> error X

	//goo("banana", "apple");		// error
	// const char[7] => const char[7]
	// const char[6] => const char[6]
	// 배열 참조로 받으면 배열로 받게 됨
	// T는 2개의 다른 타입으로 deduction됨.
}