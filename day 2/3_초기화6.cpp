// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };		// direct reset
	int n2 = { 0 };		// copy reset
	int n3;				// default reset -> 지역변수라면 쓰레기값
	int n4{};			// value reset - {} 안에 값이 없다.
						// => primitive 타입은 0으로 초기화
						// => user define type은 디폴트 생성자

	std::cout << n4 << std::endl; // 0

	Point pt{};			// 모든 멤버 0으로 초기화
						// 단, 컴파일러가 만든 생성자에서만
						// 사용자 정의 default 있으면 ㄴㄴ 
	std::cout << pt.x << std::endl;
}


