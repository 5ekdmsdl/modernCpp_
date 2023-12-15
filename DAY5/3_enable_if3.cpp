#include <iostream>
#include <type_traits>

// enable_if 기술 사용법
// std::enable_if<조건, 타입>::type의 최종 결과
//					조건 == true  : "타입" 
//					조건 == false : "::type" 없어서 error

// 아래 리턴 타입의 코드가 핵심입니다.
template<typename T>

// T에 의존해서 type 꺼낼때 typename 꼭 사용해야
typename std::enable_if< std::is_integral_v<T>, T>::type;
			// T가 정수라면, 최종 결과(리턴타입) : T
			// T 정수 아니라면, "::type" 없음. 함수 생성 실패
			// SFINAE 규칙 따라 -> 에러 후보에서 제외


// T에 의존해서 type 꺼낼때 typename 꼭 사용해야		
//typename std::enable_if< std::is_integral_v<T>, T>::type;
// 또는 아래 처럼 표기
template<typename T>
std::enable_if_t<std::is_integral_v<T>, T>;


gcd(T a, T b)
{
	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);			// T 버전 사용
	gcd(3.1, 5.4);		// exactly matching -> double 버전 사용
	gcd(3.1f, 5.4f);	// 함수 생성 실패 ->T 버전이 후보에서 제외 
						// -> double 버전 사용
}