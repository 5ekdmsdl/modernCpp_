// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 컴파일러가 만드는 복사 생성자의 정확한 모양
	// #1. call by value
	//	Point p3(p2) 에서 p2가 전달될때 또 복사 생성자 호출
	//	컴파일 에러!
	Point(const Point& other) : x(other.x), y(other.y) {}

	// #2. call by non-const (lvalue) reference
	// 에러 X , 근데 rvalue 받을 수 없네.
	// Point ret = foo(); <- 에러!
	Point(Point& other) : x(other.x), y(other.y) {}
	
	// #3. call by const (lvalue) reference
	// C98 시절 유일한방법
	Point(const Point& other) : x(other.x), y(other.y) {}

};

int main()
{
	Point p1;		// 1번 생성자
	Point p2(1, 2); // 2번 생성자
	Point p3(p2);	// Point 복사 생성자 필요 -> 컴파일러가 작성	

	Point ret = foo();	// 복사 생성자 인자가 Point& 면 에러!
}




