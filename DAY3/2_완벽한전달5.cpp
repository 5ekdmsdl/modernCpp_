#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
/*
template<typename F>
void chronometry(F f, int& arg)
{
	//f(arg);					// A
	f(static_cast<int&>(arg));	// B : 필요없는 캐스팅이지만 성능 저하 X 
								// (컴파일 시간에 제거)
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

template<typename F, typename T>
void chronometry(F f, T&& arg) {
	f(static_cast<T&&>(arg));
}

// 결국 int&, int&& 버전이 필요하고, int 뿐만아니라 다른 타입도 가능해야
// T&& 사용하면 위 2개 자동생성 (int 뿐만 아니라 모든 타입에서)
// but, 템플릿으로 함수 자동생성하려면 함수의 구현이 같아야!

int main()
{
	int n = 3;
	// 생성되는 함수 모양 & 캐스팅 코드 예측하기 (중요)
	chronometry(foo, 10);
			// 10:rval, T:int, chro(F f, int&&)
			// static_cast<int&&>(arg) -> int&& (rval)
	chronometry(goo, n);
			// n :lval, T:int&, chro(int&)
			// static_cast<int&>(arg) -> int& (lval)
}
