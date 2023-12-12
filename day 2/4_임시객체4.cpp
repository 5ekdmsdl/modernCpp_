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

void f1(Point  pt) {}		// call by value
void f2(Point& pt) {}		// call by ref

//int main()
//{
//	Point p(0, 0);
//	f1(p);
//	f2(p);
//}

Point pt(1, 2);

// 함수의 리턴 타입도 "value" "ref"에 따라 동작 다르다.

Point foo()		// return by val -> 임시 객체 return 
{
	return pt;
}t;

Point& goo() {
	return pt;	// 복사본 X, pt의 별명 return
}

int main()
{
	foo().x = 10;	// 임시 객체 등호의 왼쪽 X -> compile error
	goo().x = 10;	// ok,  객체 ref 
}







