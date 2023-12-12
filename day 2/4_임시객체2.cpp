// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	// #1. 임시 객체는 = 왼쪽에 올 수 X - lval가 될 수 X,
	// => 임시객체는 rval
	pt.x = 10;			
	Point(1, 2).x = 10;			// error
						
	// #2. 임시 객체는 주소 연산자로 주소 구할 수 X
	Point* p1 = &pt;			//ok		
	Point* p2 = &Point(1, 2);	// error
							
	// #3. 임시 객체 : non-const 참조 가르킬 수 X
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error

	// #4. 임시 객체는 const 참조로 가르킬 수 있다.
	const Point& r4 = Point(1, 2);	// 임시 객체 수명이 r4로 연장
							// => lifetime extension
	r4.x = 10;				// 근데 상수성 때문에 변경 X

	// ========================================
	// Cpp11 (증요)
	// #5. C++!1 만들때 상수성 없이 임시객체를 가르키고 싶었다.
	// move, perfect forwarding 때문에
	// => rvalue reference 문법 도입.
	Point&& r5 = Point(1, 2);
	r5.x = 10; // ok
}





