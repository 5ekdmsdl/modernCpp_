#include <iostream>
#include <type_traits> // 이 헤더에 많은 traits 가 이미 만들어져 있습니다.
// C++11 에서 제공되는 헤더

// cppreference.com 에서 1번째 화면에서 type_tratis 선택해 보세요


template<typename T> void printv(const T& v)
{
	// if : 실행 시간 조건문, 컴파일 시간에 조건 false여도
	//		템플릿 -> 실제 함수만들때는 포함됨.
	//		단지, 실행만 안되는거
	// => 해결책
	// => 컴파일 시간에 함수를 제외하자. -> 컴파일 시간 조건문
	// 
	// if constexpr : 컴파일 조건문, 컴파일 시간에 조건 false면,
	//				  템플릿 -> 실제 함수 포함 X
	//				  단, Cpp 17 부터 가능
	
	//if (std::is_pointer<T>::value)
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;

	//else if constexpr (std:: ... )

	else
		std::cout << v << std::endl;

	// => 아무리 조건문 많아도 가져다쓸때에는 핵심만 가져감!
	// => 라이브러리 만들때 짱!
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

