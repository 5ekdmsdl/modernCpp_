// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e) {
}
int main()
{
	// std::initializer_list<int> 
	// -> 초기값을 배열과 동일한 구조로 메모리에 만들고,
	// -> 해당 메모리를 가르키는 "포인터 쌍" or "주소+갯수"

	std::initializer_list<int> e = { 1,2,3,4,5 };
	
	// vector 차이점
	// vector는 데이터가 heap에 존재.
	
	// 배열 차이점
	// 배열 자체는 함수 인자롤 사용할 수 X

	// 언제 사용?
	// => 주로 생성자 인자로 사용

	// 사용법은 STL 처럼

	// 함수인자로 initializer_list 쓰는 방법
	foo({ 1,2,3 });
}


