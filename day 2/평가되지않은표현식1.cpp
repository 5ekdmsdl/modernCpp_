// 평가되지않은표현식1.cpp

#include <typeinfo>
int add(int a, int b) { return a + b; }

int main()
{
	// #1. expression(표현식) : 한개의 값으로 결정되는 코드 집합
	int n = 10;
	
	n * 2 + 3;
	add(1, 2);

	// #2. decltype() 의 () 안에는 expression 을 적어야 합니다.
//	decltype(int) d;  // error. int 라는 타입이 아닌 expression 을 넣어야 합니다.


	// #3. decltype(exp) : exp 이 생성하는 값의  타입을 결정하는 것
	decltype( add(1, 2) ) ret = add(1, 2);
	// 오른쪽 exp : 진짜 호출
	// 왼쪽 exp : 컴파일러에게 알려주는 것만 => unevaluated expression
	// => 평가되지 않는 표현식

	// ## Cpp의 평가되지 않는 표현식 종류 4가지
	// decltype, sizeof, noexcept, typeid
	decltype(add(1, 2)) d;
	int n = sizeof(add(1, 2));
	bool b = noexcept(add(1, 2));
	const std::type_info& t = typeid(add(1, 2));

	// ================================================
	// 우변의 타입을 auto가 아닌 decltype 규칙으로 결정해달라.
	// = auto 자리에 우변의 표현식을 넣어달라.
	decltype(auto) ret = add(1, 2);
}
