// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� Ư¡ - 79 page
int main()
{
	Point pt(1, 2);
	
	// #1. �ӽ� ��ü�� = ���ʿ� �� �� X - lval�� �� �� X,
	// => �ӽð�ü�� rval
	pt.x = 10;			
	Point(1, 2).x = 10;			// error
						
	// #2. �ӽ� ��ü�� �ּ� �����ڷ� �ּ� ���� �� X
	Point* p1 = &pt;			//ok		
	Point* p2 = &Point(1, 2);	// error
							
	// #3. �ӽ� ��ü : non-const ���� ����ų �� X
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error

	// #4. �ӽ� ��ü�� const ������ ����ų �� �ִ�.
	const Point& r4 = Point(1, 2);	// �ӽ� ��ü ������ r4�� ����
							// => lifetime extension
	r4.x = 10;				// �ٵ� ����� ������ ���� X

	// ========================================
	// Cpp11 (����)
	// #5. C++!1 ���鶧 ����� ���� �ӽð�ü�� ����Ű�� �;���.
	// move, perfect forwarding ������
	// => rvalue reference ���� ����.
	Point&& r5 = Point(1, 2);
	r5.x = 10; // ok
}





