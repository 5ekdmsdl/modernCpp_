#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	//	  아래 코드는 동적 메모리를 몇번 할당 할까요 ?
	// => new Point 때문에 1회 호출
	// => spointer control block 만들면서 1회 호출
	std::shared_ptr<Point> sp1(new Point(1,2));

	// 2. std::make_shared
	// => Point 객체와 control block을 붙여서 한번에 할당 -> 메모리 효율 굿
	// => new Point에서는 X
	//		라이브러리 내부에서 "sizeof(Point) + sizeof(control block)" 한번에 할당해야
	
	std::shared_ptr<Point> sp = std::make_shared<Point>(1,2);
	// => sizeof(Point) + sizeof(control block) 한번에 할당
	// => 인자로 전달된 1,2를 Point 생성자로 "완벽 전달"
	// => 해당 메모리 관리하는 shared pointer 생성하고, return
}

// main						make_shared				Point(int a, int b)
// (1, 2) ===================> 받은 인자를 다시 =========> 이곳으로 전달






