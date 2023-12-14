// 람다 표현식은 함수 포인터에 담을 수
// ==> 원리 생각해보자...
#include <iostream>
class ClosureType
{
	int v1;
	int v2;

public:
	ClosureType(int a, int b) : v1(a), v2(b) {}

	inline int operator()(int a, int b) const { return v1 + v2 + a + b; }

	// static 함수 -> 멤버 함수 접근 X			=> error!
	static int helper(int a, int b) { return v1 + v2 + a + b; }

	using PF = int(*)(int, int);
	operator PF() { return &ClosureType::helper; }
};

int main()
{
	int v1 = 0; int v2 = 0;

	// 캡쳐한 람다 표현식 : 함수 표현식으로 변환 불가!!
	//   => 아래 코드는 에러!!
	//	 => 캡쳐하지 않은 람다 표현식만 함수 포인터 변환 가능
	//int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = ClosureType();

	int n = f(1, 2);

	std::cout << n << std::endl;	// 3

}












