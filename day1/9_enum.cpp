// 9_enum - 32 page

enum Color {
	red = 1,
	green = 2,
};

void foo(int dayofaweek) {}

int main()
{
	int c1 = Color::red;
	// #1. enum 단점 : Color 생략 -> 누구 출신인지 모르겠음.
	int c2 = red;

	int red = 2;
	auto c2 = red;
	// 여기서 c2는 더 가까운 지역변수 red를 채택 -> c2 == 2

	// #2. int로 암시적 변환이 가능한 위험 코드...	
	int c4 = Color::red;
	c4 = 100;

	// ==> 엄격한 enum이 필요하다!!

	foo(0);  
}





