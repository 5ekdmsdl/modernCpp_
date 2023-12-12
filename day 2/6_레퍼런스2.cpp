#include <iostream>

// 90 page
// 동일 이름의 함수 3가지 형태 overload 가능
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// lvalue -> (1), (2) 호출 가능
				// 근데, n != const -> (1) 호출,
				// (1) 없으면 (2) 호출

	foo(10);	// rvalue -> (2), (3) 호출 가능
				// (3) 호출
				// (3) 없으면 (2)
	
	// **중요**
	// lvalue, rvalue 다르게 동작하려면 : (1), (3)처럼 두개 만들기
	// lvalue, rvalue 한개의 함수로 처리 : (2)처럼 만들기
	
	int& r1 = n;
	foo(r1);	// (1), 없으면 (2)


	int&& r2 = 10; 
	foo(r2);	// (1) 호출 ((3) 아니고!)

	// 타입과 value category를 헷갈리지 마세요.
	//				타입		value 속성
	//	n			int			lval		
	//	10			int			rval
	//	pt			Point		lval
	//	Point(1,2)	Point		rval
	//	r1			int&		lval
	//	r2			int&&		rval (이름이 있잖아!)
	//							(10은 rval이지만 r2는 lval)
	// ---------------------------------------------------
	// 타입이 아니라 value 속성에 의해 호출 함수 정해지는 것!

	Point&& r = Point(1, 1);
	// Point(1,1)은 rvalue, 즉, 등호의 왼쪽에 올 수 X
	// but, r이라는 코드는 lvalue, 등호의 왼쪽에 올 수

	r.x = 10;

	//#2. 함수 인자의 의미를 정확하게 이해하세요.
	// f1(int&) : int& 타입 받겠다. (X)
	//				=> lvalue 받겠다.
	// f1(int&&) : int&& 타입을 받겠다 (X)
	//				=> rvalue 받겠다.
	
	// #3. 
	int&& r3 = 10;
	foo(r3);						// (1) callback. 
									// r3 타입:int&&, r3 속성:lvalue
	foo(static_cast<int&&>(r3));	// (3) callback
			// => r3의 타입이 int&& 인데 ???
			// => 다시 int&& 로 캐스팅???
			// => 결국 같은 타입 아닌가요 ?? 이게 어떤 의미가 있지요 ??

	// static_cast<Type>(r3) 에서 Type 이 && 가 붙어 있는 경우
	// => "타입 캐스팅" 이 아닌 "value 속성을 변경하는 캐스팅" 입니다.
	// => cppreference.com 에서 "static_cast" 찾아 보세요
}

// 표현식 : 하나의 값으로 계산되는 코드 집합
// 1 표현식 -> 타입 + value 속성 (category)
// 코드의 연산의 결과가 만든 값 -> rvalue







