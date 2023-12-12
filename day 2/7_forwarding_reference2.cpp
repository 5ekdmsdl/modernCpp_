// 91 page
int main()
{
	int n = 10;

	// #1. 포인터는 "이중 포인터"를 만들 수 있다.
	int *p = &n;
	int* *pp = &p;

	// #2. reference는 이중 X
	int& r = n;
	int& &rr = r;		// error

	// #3. 타입 추론, 또는 using 사용시 발생하는
	//	레퍼런스의 레퍼런스는 아래 규칙 계산
	using LREF = int&; 
	using RREF = int&&;

	// (외우기!) reference collapsing 규칙 
	LREF& r3 = ? ;	// int& & -> int&
	RREF& r4 = ? ;	// int&& & -> int&
	LREF&& r5 = ? ;	// int& && -> int&
	RREF&& r6 = ?;	// int&& && -> int&&
	// && + && 일떄에만 결과 &&!

	// 아래 foo를 생각해보세요.
	foo<int&>(n);

	int x[3] = { 1,2,3 };
	decltype(x[0])& r;	// int& & r -> int& r
}

template<typename T> void foo(T a)
{
	T& r = a;		// int& & r = a;
					// => int& r = a;
}





