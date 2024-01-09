// 8_nullptr2
#include <iostream>

void foo(int* p) {}

// 인자로 "함수"와 "인자"를 받아서
// => "함수(인자)" 형태로 호출하는 함수
template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}

int main()
{
	foo(0); // ok
	//forward_parameter(foo, 0); 
	// foo(0)이 아니라 foo(int(0)) 이 됨 -> error
	// template에서 type deduction 거치면서 type 바뀜
	// => 그래서 nullptr 도입!

	forward_parameter(foo, nullptr); // 든든....


}








