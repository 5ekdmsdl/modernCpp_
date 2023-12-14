// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다 표현식이 만드는 클래스의 operator() : 상수 멤버 함수
	//     => 그래서 "v1 = 100" error
	auto f2 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; };
	// 람다 표현식으로 만드는 함수 = 상수 함수 -> 값 못 바꿈...

	// #2. mutable 람다는 operator() 상수 함수 X
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };
	f1(0);		// 여기서 v1 = 100; 실행되지만 
				// main의 지역변수 X, f1 객체의 복사본을 수정한것


	// =======================================================
	// 람다식을 보고 컴파일러가 만드는 객체는 아래 같이...

	class CompilerGeneratedName {
		// 지역 변수 캡처 -> 멤버 데이터 추가
		int v1;
		int v2;

	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a) const {
			v1 = 100;
			return a + v1 + v2;
		}
	};

	auto f1 = CompilerGeneratedName(v1, v2);


}







