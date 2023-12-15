#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	printv(args...);		// error, printv(1, 2, 3)의 의미 

	printv(args)...;		// printv(1), printv(2), printv(3)의 의미 
							// 근데 error
							// pack expansion 될 수 X
	
	// #1. pack expansion 아래 위치에서만 가능
	// 1. 함수 호출의 () 안			: goo(args...)
	// 2. 템플릿 인자의 <> 안		: std::tuples<Types...>
	// 3. {} 초기화 사용			: int x[] = {args...};
	
	// args 의 모든 요소를  printv 에 보내려면
	// => 아래 방법은 Cpp 11 처음 나왔을때 사용했던 코드
	// => 지금은 더 좋은 방법 있음 (fold expression)
	int x[] = { 0, (printv(args) , 0)... };
		//	{ 0, (printv(1), 0) , (printv(2), 0), (printv(3), 0) }


}


int main()
{
	foo(1, 2, 3);
}

