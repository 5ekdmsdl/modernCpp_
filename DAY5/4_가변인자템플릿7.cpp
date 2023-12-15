#include <iostream>

// 언제 가변인자 템플릿 사용하나요?
// => 가변인자 템플릿 사용하는 전형적인 예제들 존재

// 1. 완벽한 전달 : 대부분 가변인자 템플릿 사용
// 2. std::tuple, std::get 같은 코드는 가변인자 템플릿으로 만듦.
// 

void foo(int a, int b, int& c) { c = 100; }

//// 아래처럼 만들면, chronometry는 인자 1개짜리만 forward 가능
//template<typename F, typename T>
//decltype(auto) chronometry(F f, T&& args)
//{
//	return f( std::forward<T>(arg)); 
//}

// 아래처럼 만들면, chronometry는 인자 무제한 forward 할 수
template<typename F, typename ...Types>
decltype(auto) chronometry(F f, Types&& ...args)
{
	//return f(std::forward<T>(arg));		// forward(E1, E2, E3)
										// forward는 인자 1개

	return f(std::forward<Types>(args)...);
			//   f( std::forward<Types>(E1),
			//		std::forward<Types>(E2),
			//		std::forward<Types>(E3) );

}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

