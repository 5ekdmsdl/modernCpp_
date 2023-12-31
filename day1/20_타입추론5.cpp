// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	auto a = 10;

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	auto a1 = n;  // a1 :
	auto a2 = r;  // a2 :
	auto a3 = c;  // a3 :
	auto a4 = cr; // a4 :

	auto& a5 = n;  // auto :  ?   a5 : ?
	auto& a6 = r; 
	auto& a7 = c; 
	auto& a8 = cr;
}


