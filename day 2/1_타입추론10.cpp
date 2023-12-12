int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// #1. auto vs decltype
	auto a = x[0];			// int a = x[0]
	decltype(x[0]) d;		// int& d

	// #2. 
	auto ret1 = foo;		// foo() 반환타입 int& -> auto : int
	// decltype(함수 호출식) : 함수 반환 타입, 함수 선언보고 결정
	decltype(foo()) ret2 = foo();  // int& ret2 = foo();
	// decltype 안의 함수는 컴파일 타임에 바뀐다 -> 호출 X

	// #3. decltype(auto) : C++14부터 지원
	// => auto 자리에 우변 놓아라.
	// => 우변으로 타입 추론 -> 규칙은 decltype으로 하라.
	decltype(auto) ret3 = foo();
	
	// ret1 : int 변수, 
	// ret 2,3 int& -> X의 별명
}

