#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

// 아래 코드는 "복사" 기반 swap -> Cpp98 시절 C++ 표준 구현
// => 성능 좋지 않다!
template<typename T>
void Swap(T& a, T& b) {
	T tmp = a;		// 복사 생성자 잔뜩 호출
	a = b;
	b = tmp;
}

// Cpp 11에서 swap 구현
// 이동을 사용한 swap -> 복사 버전보다 훨빠름 (string 이면 더)
template<typename T>
void Swap(T& a, T& b) {
	T tmp = std::move(a);		// 복사 생성자 잔뜩 호출
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move 라는 주제에서 알아야하는 것
// 1. swap 알고리즘 작성시, std::move 사용하면 성능 향상
// 2. std::string 같은 표준 라이브러리 말고,
//		사용자 define class 쓰려면 어떻게 해야하나



