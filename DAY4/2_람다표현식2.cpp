// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// 람다표현식의 원리!
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	//=======================================================
	// 위 코드를 컴파일러가 아래처럼 변경합니다.
	
	//class CompilerGeneratedName	// 람다 표현식이 만드는 클래스 이름 : 컴파일러가 임의로 결정
	class ClosureType				// 일반적으로 문서들은 요 이름 사용
	{								// Closure를 만드는 type이라는 의미.
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

	// 람다의 최종 결과 = 결국 "임시 객체"
	// lambda expression에서 "expression"은 하나의 값으로 계산되는 코드 !
	// => 함수 객체를 임시 객체 형태로 생성한 것
	// => 결국, "클로져" 만든 것
	// => cppreference.com의 1번쨰 화면에서 expression 선택
	//  문서 중간에 "lambda expression" 선택 -> 1번째 설명 읽기



}





