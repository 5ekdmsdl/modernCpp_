// 9_enum - 32 page

// Cpp11 enum은 class가 붙어야한다.
enum class Color {
	red = 1,
	green = 2,
};

void foo(int dayofaweek) {}

int main() {
	// auto c1 = red;			//-> type 이름 생략 불가능
	// int c1 = Color::red;		//-> int에 담기 불가능

	// 규칙이 엄격해짐 -> 단 버그 확률 급감~!
	Color c2 = Color::red;
}





