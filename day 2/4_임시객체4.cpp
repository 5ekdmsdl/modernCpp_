// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

void f1(Point  pt) {}
void f2(Point& pt) {}


Point pt(1, 2);

Point foo() 
{
	return pt; 
}

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}







