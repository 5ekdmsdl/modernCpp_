// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	auto a = r;		// int a = r;
					// auto : ref 제거

	// decltype(exp) 규칙 1. exp에 심볼 이름만 있을때
	// 심볼의 선언 보고, 동일 타입으로 결정

	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2			(초기값 X error)
	decltype(c) d3; // const int d3		(초기값 X error)
	decltype(p) d4; // int* d4
}