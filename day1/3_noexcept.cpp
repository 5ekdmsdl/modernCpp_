// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 키워드는 2가지 용도
// 1. 표현식에 예외 검사
//    => bool b = noexpcept(expression)
//    => 함수 구현 자체 조사 X, 함수 선언에 noexcept 있는지만 확인
// 
// 2. 함수에 예외 없음/있음 알릴때

void foo()          // 예외 가능성 있는 함수  
{
}

void goo() noexcept	// 예외 가능성 없는 함수
{
}

int main()
{
	bool b1 = noexcept(foo());
	// 예외 가능성 있기 때문에 b1 = false
	bool b2 = noexcept(goo());
	// goo는 noexcpet니까 b2 = true

	std::cout << "b1" << "," << b2 << std::endl;
}

// move 할때 noexcept 활용 예정!







