// 람다 표현식은 함수 포인터에 담을 수
// ==> 원리 생각해보자...
#include <iostream>
class ClosureType
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// static 멤버 함수는 객체 없이 호출 -> this 없이 호출 가능
	// 함수 표인터로의 변환 위해 operator() 똑같은 static 멤버 함수 제공
	static int helper(int a, int b) { return a + b; }

	// 함수 포인터로의 변환을 위해 변환 연산자 추가된다.
	using PF = int(*)(int, int);
	operator PF() { return &ClosureType::helper; }
					// error
					// 일반 함수 포인터에 멤버 함수 주소 넣을 수 X
};

int main()
{
	//int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = ClosureType();
						// 임시객체.operator 함수포인터타입();

	int n = f(1, 2);
	
	std::cout << n << std::endl;	// 3

}












