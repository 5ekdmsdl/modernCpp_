#include <iostream>

// nullptr 의 정체!!
// => 직접 만들어 봅시다.
// 1. boost에서 진짜 저렇게 씀.
// 2. C11 표준에서 채택됨.
// => 근데 표준에서는 nullptr가 키워드라 객체는 아님.

void foo(int* p) {}
void goo(char* p) {}

// ===============================================================
struct mynullptr_t
{
	// 변환 연산자 : 객체가 다른 타입으로 암시적으로 변환할때 호출
	//operator int* () { return 0; }
	//operator char*() { return 0; }

	template<typename T>
	inline operator T* () const { return 0; }
};
mynullptr_t mynullptr;
// ================================================================

int main()
{
	foo(mynullptr);
	goo(mynullptr);

	// # nullptr의 literal & type
	// literal : nullptr 프로그램에서 사용하는 값
	// type : std::nullptr_t 
	std::nullptr_t p = nullptr;
	foo(p);
}