int main()
{
	int n = 3;

	// 다음중 에러를 모두 고르세요!
	auto& a1 = n;
	auto& a2 = 3;

	// auto는 T와 규칙 동일
	// auto&& == T&&
	// auto&&는 rvalue reference X -> forward reference
	// -> 아래 코드 모두 에러 X
	auto&& a3 = n;	// n:lvalue, auto&&:int&, // -> int& a3
	auto&& a4 = 3;	// 3:rvalue, auto&&:int&& -> int&& a4

}

