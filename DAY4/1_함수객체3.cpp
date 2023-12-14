#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

// #1. 일반 함수는 동작만 있고 상태(저장할 공간)가 없습니다.
bool foo(int n) { return n % 3 == 0; }

// #2. 함수 객체는 동작과 "상태(멤버 데이타)" 가 있습니다.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	// () 연산자 함수가 인자가 한개이므로 단항 함수객체 입니다.
	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k); // f 는 k의 값을 내부적으로 보관합니다.
	bool b = f(10); // 10 % k(3) 의 연산 수행.. 즉, k 로 나누어 떨어지는가 조사.
	
	auto p2 = std::find_if(v.begin(), v.end(), f );
	// 한번만 쓸거면 임시객체로
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide(k) );
	// find_if(first, last, "main 지역변수 k + 단항함수" 전달

	// "closure"
	// => 자신이 속한 문맥의 지역변수를 "캡쳐"할 수 있는 함수
	// IsDivide는 main 함수의 k를 캡쳐함.
	// 일반 함수는 closure X, 근데 함수 객체는 가능

	// C++에서 일반 함수 : 클로져 될 수 X
	// C++에서 함수 객체 : 클로져 O

	// closure : 대부분의 언어가 사용하는 용어
}



