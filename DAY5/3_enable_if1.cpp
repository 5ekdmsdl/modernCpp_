// 6_enable_if1.cpp
// 아래 코드 (enable_if) 이미 Cpp11 표준에 있음.

template<bool, typename T = void > struct enable_if
{
	using type = T;
};
// type 값 없으면 default void

template<typename T> struct enable_if<false, T> 
{
	// 핵심 : type 멤버가 없다!
};

// enable if 사용법 : enable_if<bool 값, 타입>
// 핵심 : 1번째 인자 false -> 부분 특수화 버전 제공

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1;		// int n1
	enable_if<true>::type       n2;		// void n2
	enable_if<false, int>::type n3;		// (::type 없어서) error

	// enable_if 꼭 기억할 것
	// 1. enable_if<false, 타입>::type은 에러, type이 없다.
	// 2. enable_if<true,  타입>::type -> "타입"
	// 3. enable_if<true>::type		   -> "void"
	//



}


