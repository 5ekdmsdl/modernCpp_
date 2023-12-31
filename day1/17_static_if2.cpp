// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	// # case 1 : 그냥 if
	// 아래는 컴파일 error, 
	// 왜냐면... 
	// if : 실행 시간 제어문
	// 조건문이 컴파일 시간에 false이더라도 인스턴스화된 함수에 포함된다.

	/*if (false)
		*a = 10;*/

		// # case 2 : "static if" == "if constexpr"
		//  if constexpr :  컴파일 시간 제어문
		//                 조건문이 컴파일 시간에 false 로 결정되면
		//				   인스턴스화된 함수에는 포함 안됨.
		//				   C++17

	if constexpr (false)
		*a = 10;
}
int main()
{
	foo(0);
}

