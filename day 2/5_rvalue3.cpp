#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	n + 5 = 20; // error. "n + 5" 는 rvalue

	// lvalue, rvalue 조사하려면
	// -> decltype의 규칙을 생각하라.
	using T = decltype(n + 5);
	// decltype : lvalue -> T : 참조
	//			  rvalue -> T : 값 타입
	using T2 = decltype(++n);
	using T3 = decltype(n++);
	using T4 = decltype(n);		// n : lvalue지만, 
								// 이름만 있다 -> 참조 타입

	if (std::is_lvalue_reference_v<T>)
		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;
}