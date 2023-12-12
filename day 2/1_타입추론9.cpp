// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// decltype 규칙 1. 심볼 이름만 있으면
	// 해당 변수와 동일 타입
	decltype(p)		d1; 

	// 규칙 2. exp에 "심볼 이름+표현식(연산자)"
	// exp가 등호 왼쪽(rval)에 올 수 있으면 ref 타입
	// 아니면 value 타입
	decltype(*p)	d2;  // *p = 10 가능-> int& d2		(초기값 error)
	decltype(x[0])	d3;	 // x[0] = 10 가능 -> int& d3

	decltype(n) d;		// n = 10 가능, 근데 심볼만 있음 
						// -> 선언으로 결정 -> int d
					

	decltype(n + n) d4;  // n + n = 10 (X) -> int d4
	decltype(++n)   d5;  // ++n = 10 (O)   -> int& d5
						
						
	decltype(n++)   d6;  // n++ = 10 (error) -> int d6
	
	++n = 10;
}

// 참고 : 왼쪽 값 = 결국에는 참조
//int x = 0;
//int  f1() { return x; } // x의 값 0 반환
//int& f2() { return x; } // x의 값 0이 아닌 별명을 반환
//
//int main()
//{
//	f1() = 10; // error. 0 = 10 의 의미.
//	f2() = 10; // ok.    x = 10 의 의미.
//}

/* 참고 : ++n과 n++ 차이점
// operator++ 을 primitive 타입에 대해서 overloading 할수 없지만, 설명을 위해
// 전위형 ++
int& operator++(int& a)
{
	a = a + 1;
	return a;
}
int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}
*/

