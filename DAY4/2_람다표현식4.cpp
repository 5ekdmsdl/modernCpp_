// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	// #1. 모든 람다 표현식은 다른 타입!
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx();
	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy();

	std::cout << typeid(f1).name() << std::endl;

	// #2. 람다 표현식으로 초기화된 변수에, 다른 람다 표현식 담을 수 x
	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; };		// 타입이 달라서 error!

	// #3. 
	std::vector<int> v = { 1,2,3 };
	// 아래 코드는 sort 3개 생성됨!
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });

	auto cmp = [](int a, int b) { return a < b; };
	// 여기서는 sort 1개 생성됨!
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	// 참고로 얘는 inline 된다.

	// 한번만 쓸거면 임시 객체 ok, 근데 여러번 사용될거면 auto 변수에 담자.

	// 어차피 연산 <이 필요하면, "std::less" 사용해도 좋다.
}





