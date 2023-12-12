// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}
void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	Point pt(1, 2);
	foo(pt);

	std::cout << "-----" << std::endl;
}





