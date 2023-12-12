// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	// T a = 10;	// 아래 auto 코드와 동일
	auto a = 10;	// auto 추론 == 템플릿 추론 (거의)

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// auto -> 규칙 1. 값으로 받으면
	// const, volatile, refer 모두 제거
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// auto& -> 규칙 2. 우변의 ref만 제거
	auto& a5 = n;  // auto : int        a5 : int&
	auto& a6 = r;  // auto : int	    a5 : int&
	auto& a7 = c;  // auto : const int  a5 : const int&
	auto& a8 = cr; // auto : const int  a5 : const int&

	
	int x[3] = { 1,2,3 };

	// x : int[3]
	auto  a11 = x;	// 배열로 결정 -> 배열 복사X
					// => auto : 배열 pointer
					// auto int* a11 = x;
	auto& a12 = x;	// 참조 => auto : 배열
					// int(&)[3] a12 = x;
}


