#include <iostream>

// #1. 배열 값전달 -> T = 배열 포인터   (int*)
template<typename T> void foo(T a)
{
	std::cout << __FUNCSIG__ << std::endl;
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// #2. 배열 참조 -> T = 배열 (포인터 X) (int[3])
template<typename T> void goo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };
	
	// x의 타입 : int[3]
	// 근데 T == int[3] 라면 복사 불가능
	foo(x); // 만약 T 를 int[3] 로 결정하면
			// int a[3] = x; 가 됩니다. 배열은 복사가 안되므로 컴파일 에러!!
			// int* a = x;   로 결정했다면 ok.

	goo(x); // T = int[3]이면 
			// int(&a)[3] = x;
			// 배열 가르키는 참조는 에러 X
}