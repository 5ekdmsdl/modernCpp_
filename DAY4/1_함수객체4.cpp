       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출. 인자를 약속된 장소에 넣고, 
						 // Add1 의 위치로 이동
	int n2 = Add2(1, 2); // 치환. 요기에 Add2의 기계어 코드로 변환
						 // 빠르다!

	int(*f)(int, int) = &Add2;

	// if( user_input == 1) f = &Add1;
	// 컴파일 타임에 f가 누구인지 알 수 X

	f(1, 2); // inline 치환 -> 호출!!
}

// 1. 인라인 치환 : "컴파일 시간"에 수행
// 2. 인라인 함수라도 함수 포인터에 넣어서 호출하면 인라인 치환 X



