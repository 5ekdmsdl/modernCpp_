// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. 람다표현식에서 전역변수
	auto f1 = [](int a) { return a + g; };
	
	// 2. 람다표현식에서 지역변수 접근
	//auto f2 = [](int a) { return a + v1 + v2; };
	
	// 3. 람다표현식에서 지역변수 접근하려면 지역 변수 캡쳐 해야
	auto f2 = [v1, v2](int a) { return a + v1 + v2; };

	// 4. 캡쳐된 지역 변수 변경
	// => mutable 람다는 가능
	auto f3 = [v1, v2](int a) { v1 = 10; return v1 };	// error
	

}





