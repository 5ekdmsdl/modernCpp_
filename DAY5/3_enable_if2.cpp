#include <iostream>
#include <type_traits>

// 대충 최대 공약수 구하는 함수
// 최대 공약수는 정수에만 적용해야
template<typename T> T gcd(T a, T b)
{
	// 방법 1: static_assert
	// => static_assert는 조건 만족 X -> error
	// => 조건 만족 안해도 
	// 후보군에서 제외되는게 낫지 않을까.
	static_assert(std::is_integral_v<T>, "error, not integral");

	return 0;
}

void gcd(double a, double b) {  }

int main()
{
	gcd(6, 9);			// T->int 버전 사용
	gcd(3.1,  5.4);		// double 버전 사용
	gcd(3.1f,  5.4f);	// T->float 버전 사용 -> assert fail




	
}