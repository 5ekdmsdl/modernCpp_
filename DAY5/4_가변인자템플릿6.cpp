#include <iostream>

// recursion 
// 1. 모든 인자를 가변인자로 하지 말고
// 2. 1번째 인자는 독립된 인자(이름있는 변수) 로 받으세요

// 주의 : 아래 코드는 재귀 호출 X
// main => foo(인자3개) => foo(인자2개) => foo(인자1개) => foo() 형태
// => 즉, 모두 다른 함수 호출
//			-> 인자 너무 많으면 코드 너무 커지니까 권장 X

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value;

	// Cpp 17 이전
	//foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()		==> 이 경우를 위해서 인자없는 foo 필요

	// Cpp 17 이후
	// if constexpr하면 인자 없는 "foo()" 는 필요 X
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,  args : 3.4,  'A'
}





