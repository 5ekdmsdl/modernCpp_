#include <iostream>

// auto 와 람다 표현식

int main()
{
//	int foo() {} // 함수 안에 함수, local function, nested function 이라고 합니다

	// #1. 람다표현식을 auto 변수에 담아서 함수 처럼 사용가능합니다.
	// => 일부 언어(C#등)는 함수 안에 함수를 만들수 있습니다.
	// => C++ 은 함수 안에 함수를 만들수 없는데
	//    아래 처럼 만들면 결국, local function 을 만든것과 동일합니다.

	auto add = [](int a, int b) { return a + b; };
				// class ClosureType{ operator()(){} }; ClosureType();

	int n1 = add(1, 2);
	int n2 = add.operator()(1, 2);	// ok.. 결국 함수 객체이므로 
									// 이렇게 사용해도 됩니다


	// #2. 다음중 에러를 모두 고르세요 - f2 한개 에러
	// 
	//     에러가 아닌 코드중 최선의 코드를 고르세요 - f1 이 최선!!!
	// 
	// 핵심 : 람다표현식의 최종 결과는 "임시객체(rvalue)" 이다.

	auto  f1       = [](int a, int b) { return a + b; }; // ok
	auto& f2       = [](int a, int b) { return a + b; }; // error.
								// => 임시객체를 lvalue reference 로 가리킬수 없다

	const auto& f3 = [](int a, int b) { return a + b; }; // ok	
			// 임시 객체를 const ref 로 받을 수 있다!
	auto&& f4      = [](int a, int b) { return a + b; }; // ok
					// auto&& 는 "forwarding reference" 인데.
					// 우변이 rvalue 이므로 auto : 값 타입, auto&& 는  타입&&(rvalue reference)


	// 최선의 코드 근거
	//auto f1 = [](int a, int b) {return a + b; };
	//auto f1 = ClosureType();		// 생성자 1회 호출, 추가 오버헤드 X
	//
	//auto&& f2 = [](int a, int b) { return a + b; };	// 임시 객체 만들고, 주소 들고 있기
	//ClosureType* f2 = &ClosureType();	// 주소를 따라가서 사용
										// 직접 접근 X -> 약간의 오버헤드 발생!

}

// 참고 : Point pt = Point(1, 2) 에 대해서 생각해 봅시다.

// Cpp 98
// Point pt = Point(1,2)
//			1. 임시 객체 생성,
//			2. 임시 객체로 pt에 복사 (복사 생성자)
//			=> 근데, 대부분의 컴파일로는 임시 객체 생성, 복사 생성 호출 생략
//			=> 대신 인자 2개의 생성자 호출 
//				(copy ellision, elide copy constructor) 
//			
//			=> (!!)그런데, Point의 복사 생성자를 private 에 넣으면 에러
// 
// Cpp 11
// Point pt = Point(1,2)
//			1. 임시 객체 생성
//			2. 임시 객체 pt로 이동 (이동 생성자)
//			=> 그런데, 역시 대부분 컴파일러는 최적화 -> 인자 2개 생성자 호출
// 
// Cpp 17
// Point pt = Point(1,2)
//			1. 인자 2개 생성자 호출
//			=> 임시 객체 생성, 복사 생략하는 것이 문법화 됨.
//			=> 복사 생성자와 이동 생성자 모두 private에 있어도 에러 X
//			=> 오버헤드가 전혀 X
// 






