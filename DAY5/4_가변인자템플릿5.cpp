#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// => args에 있는 2번째 요소 꺼내고 싶다.	=> 한번에는 x

	// #1. 아래 방법 중 한가지 사용해야
	//		1. pack expansion			- Cpp 11
	//		2. recursion 유사 코드		- Cpp 11
	//		3. fold expression			- Cpp 17

	// # pack expansion
	// 모든 요소가 같은 타입 보장 있으면 배열 담기
	int x[] = { args... };

	// 타입 다르면 tuple에 담기
	std::tuple<Types...> t = { args... };
}


int main()
{
	foo(1, 2, 3);
}

