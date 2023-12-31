#include <cassert>

// assert        : 실행시간 표현식의 유효성을 확인하는 도구, C/C++
// static_assert : 컴파일 시간에 유효성을 확인.
//					표현식이 거짓이면 컴파일 멈추고 메세지 출력.

// 무조건 컴파일타임에 확인 가능 -> 변수는 넣을 수 X
static_assert(sizeof(int*) >= 8, "error, not 64bit");


void foo(int age)
{
	// 함수 인자를 사용하기 전에 유효성을 확인하는 것이 좋습니다.
	assert(age > 0);

	int* p = new int[age];

	delete[] p;
}

int main()
{
	//	foo(10);
	foo(-10); // 실수했다.!!
}