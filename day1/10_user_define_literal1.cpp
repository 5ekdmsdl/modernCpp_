class Meter {
public:
	int value;

	Meter(int sz) : value(sz) {};

	Meter operator-() { return Meter(-value); }
};

// #핵심 1 : 인자 타입이 표준에 의해 고정되어있음
// 정수사용할때에는 unsigned long long

// 2. 표준협회쨩 : 되도록 일반 개발자는 새로운 접미사 만들지 말라
// 굳이 만들고 싶으면 _ 붙혀서 만들어라

Meter operator""_m(unsigned long long sz) {
	return Meter(sz);
}

int main()
{
	double d = 3.4;
	float f = 3.4f;		// f 접미사 : 3.4 타입을 float로 만들어라.

	//cpp11 부터 접미사 사용자 정의 가능
	Meter a = 30_m;	// operator""m(30) 호출
	//Gram b = 30g;

	-30_m;			// 30_m -> Meter 객체 생성 -> Meter operator- 호출
	
	return 0;
}




