// 1_초기화11 - 65 page..
// aggregate initialization
// => 생성자 없이 { }로 초기화 되는 것

//aggregate type
// 생성자 없이 { } 로 초기화 가능
// => 배열, 구조체, 공용체

struct Point
{
	int x, y;

	//Point()             : x(0), y(0) {}	// 1
	//Point(int a, int b) : x(a), y(b) {}	// 2

	//virtual void foo() {} // 가상 함수 있으면 aggregate reset X

	//Point() {}				// 생성자 있으면 agg type X

	Point() = default;		// 컴파일러가 만들면 agg type
};

int main()
{
	Point p1;	
	//Point p2(1, 2);	// error
	Point p3 = { 1,2 };
	// p3는 agg type인 경우에만 생성 가능 
	// -> 생성자를 컴파일러가 만드는 경우만 가능

}