// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// �ӽð�ü�� �Լ� ��ȯ�� -  82 page

void f1(Point  pt) {}		// call by value
void f2(Point& pt) {}		// call by ref

//int main()
//{
//	Point p(0, 0);
//	f1(p);
//	f2(p);
//}

Point pt(1, 2);

// �Լ��� ���� Ÿ�Ե� "value" "ref"�� ���� ���� �ٸ���.

Point foo()		// return by val -> �ӽ� ��ü return 
{
	return pt;
}t;

Point& goo() {
	return pt;	// ���纻 X, pt�� ���� return
}

int main()
{
	foo().x = 10;	// �ӽ� ��ü ��ȣ�� ���� X -> compile error
	goo().x = 10;	// ok,  ��ü ref 
}







