// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	std::sort(v.begin(), v.end()); 

	// #1. 비교함수 전달 X -  오름차순 정렬

	// #2. 비교함수 일반함수 사용 -> 인라인 X
	sort(v.begin(), v.end(), cmp));

	// #3. 비교함수 함수객체 사용 -> 인라인 가능
	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>{});

	// #4. Cpp 11 부터는 람다 표현식 사용 가능
	// [] : 람다 표현식 시작 기호 : lambda introducer
	//		"익명의 함수" 라고도 한다. 	
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });

}





