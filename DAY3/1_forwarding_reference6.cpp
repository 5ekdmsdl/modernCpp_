// 함수 인자로
// int&  : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.
// T&    : 모든 타입의 lvalue 만 받을수 있다.

// T&&   : 모든 타입의 lvalue & rvalue 받을 수 있다.
// 모두 받는다, = 각각의 경우를 받을 수 있는 함수 생성한다,

// 아래 내용 외우세요
// 인자 lvalue 전달 f4(n) : 
//			T:int&, 인자:T&&=int& &&, 생성함수:f4(int&)
// 인자 rvalue 전달 f4(3) : 
//			T:int, 인자:T&&=int&&, 생성함수:f4(int&&)

// => 즉 모든 인자를 복사본 없이 받을 수 있는 함수 생성

// 용어 정리
// int&		: lvalue reference
// int&&	: rvalue reference
// T&		: lvalue reference

// T&&		: rvalue reference는 아니고,
//				lvalue & rvalue 모두 받을 수 있다.
//				=> "universal reference" = "forwarding ref"




