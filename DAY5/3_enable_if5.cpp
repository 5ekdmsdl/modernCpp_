#include <iostream>
#include <type_traits>

//template<typename T> void printv(const T& v)
//{
//	// error : T=int일때,
//	// => 인스턴스화된 함수에 "*v"가 포함되서 에러!
//	if (std::is_pointer_v<T>)
//		std::cout << v << " : " << *v << std::endl;
//	else
//		std::cout << v << std::endl;
//}

//// if constexpr 좋긴한데,,, Cpp17부터 가능!
//template<typename T> void printv(const T& v)
//{
//	if constexpr (std::is_pointer_v<T>)
//		std::cout << v << " : " << *v << std::endl;
//	else
//		std::cout << v << std::endl;
//}

// Cpp 17 이전에는 enable_if로 해결 (요거 중요)
template<typename T> 
std::enable_if_t<std::is_pointer_v<T>>
printv(const T& v) 
{
	std::cout << "포인터 버전" << std::endl;
	std::cout << *v << std::endl;
}

template<typename T> 
std::enable_if_t<!std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << "포인터 아닌 버전" << std::endl;
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}
// https://github.com/aosp-mirror (안드로이드 소스)

// platform system core
// libutils/include/utils
