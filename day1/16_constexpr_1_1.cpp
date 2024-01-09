// 16_constexpr1
int main()
{
	int n = 10;
	// const : readonly 만들기
	const int c1 = 10;
	const int c2 = n;

	// Cpp11 constexpr : 꼭 컴파일 타임에 알 수 있는 상수 만들기
	constexpr int c3 = 10;
	constexpr int c4 = n;	// error!

	// readonly의 Cpp 공식 용어 "constant expression"
}
