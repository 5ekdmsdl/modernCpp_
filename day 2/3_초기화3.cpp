int main()
{
	// Cpp98에서 초기화 단점
	int  n1 = 3.4;	// ok, but 데이터 손실
					// C / C++ 가능하지만, 다른 언어 error
	char c1 = 500;  // 가능, but overflower

	// prevent narrow - 56 page 중간부분
	int n2{ 3.4 };  // error
	char c2{ 500 }; // error
	// 좋다....♡ 이거는 채택!!!!
}