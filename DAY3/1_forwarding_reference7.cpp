struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// lvalue & rvalue 모두 받을 수 있는 함수 만들기

// 방법 1. call by value
//	복사본 생성
void foo(Point pt) {}

// 방법 2. call by const lvalue reference
//	복사본 X, but 상수성 추가
void foo(const Point& pt) {}

// Cpp11===========================
// 방법 3.lvalue, rvalue 버전 따로 제공
// 복사본 X, 상수성 X, 
void foo(Point& pt) {}
void foo(Point&& pt) {}

// 방법 4. forwarding reference
// T&&를 사용하면 위의 2개 함수 자동 생성
// 단, Point 뿐만 아니라 모든 타입에 대해 사용 가능.
template<typename T>
void foo(T&& pt) {}



int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue(임시객체)를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
