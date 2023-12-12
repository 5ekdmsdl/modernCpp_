#include <iostream>
// 85 page
struct Base
{
	int value = 10;
};

// #1. 기반 클래스의 멤버와 동일 이름의 멤버 타이터 추가 가능
struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;
	/* 현재 d 구조
	d [Base val=10][Derived val=20]
	*/
	std::cout << d.value << std::endl; 

	// 기반 클래스 value에 접근하려면 casting
	// 차이점 중요!!! => C++23에서 중요
	std::cout << static_cast<Base&>(d).value << std::endl;
			// d를 Base처럼 보며 value 접근 -> 새로 객체 생성 X
			// -> class slicing
	std::cout << static_cast<Base>(d).value << std::endl;
			//  => (중요) d의 머리에 있는 Base 복사해서 임시 객체 생성
			//  복사 생성자 호출된다.
}

// 핵심
// 1. 임시 객체는 사용자가 의도적으로 만듦.
//		주로 함수 인자 -> draw_box(Point(1,2), Point(2,3))
// 2. 값 반환 함수, 값 캐스팅에서 임시 객체 생성
//		

