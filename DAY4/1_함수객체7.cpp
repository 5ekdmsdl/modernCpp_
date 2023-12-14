#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 템플릿 입니다.
	// => 사용자가 전달한 인자 가지고 "함수 생성"

	// 1. 비교 정책으로 일반함수 사용시
	std::sort(x, x + 10, cmp1);	// sort(int*, int*, bool(*)(int, int)) 인 함수 생성
	std::sort(x, x + 10, cmp2);	// sort(int*, int*, bool(*)(int, int)) 인 함수 생성
	// => 장점 : 같은 함수이기 때문에 code memory 증가 X
	// => 단점 : 함수 포인터로 계속 호출 (inline 치환 X) -> 속도 저하

	// 2. 비교정책으로 함수객체 사용시
	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1);	// sort(int*, int*, Less) 인 함수 생성 
	std::sort(x, x + 10, f2);	// sort(int*, int*, Greater) 인 함수 생성
	// 장점 : 비교 정책이 inline 치환 가능 -> 빠르다.
	// 단점 : 비교 정책을 교체한 횟수만큼 sort() 함수 생성 -> 코드 메모리 증가
}









