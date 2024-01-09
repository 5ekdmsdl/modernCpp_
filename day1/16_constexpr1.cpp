// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10;
	const int c2 = n;

	// 다음중 에러를 모두 고르세요
	int arr1[10];	// ok
	//int arr2[n];	// error 
	int arr3[c1];	// ok (compiler가 컴파일 타임에 값을 알고 있음.)
	//int arr4[c2];	// error

	// const 의미 : 값을 변결할 수 없다.
	//				초기값 컴파일 시간에 알수도~ 모를수도~
	// ** C#, Rust에서는 상수 X -> immutable, readonly

	// C#,swift, rust에서는
	// read only, immutable : 값 변경 X
	// constant : 컴파일 타임에 알 수 있는 것
}

// 참고 : 배열 크기
// g++은 변수 사용가능, vs는 불가능
