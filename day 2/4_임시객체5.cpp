#include <iostream>
// 85 page
struct Base
{
	int value = 10;
};

// #1. ��� Ŭ������ ����� ���� �̸��� ��� Ÿ���� �߰� ����
struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;
	/* ���� d ����
	d [Base val=10][Derived val=20]
	*/
	std::cout << d.value << std::endl; 

	// ��� Ŭ���� value�� �����Ϸ��� casting
	// ������ �߿�!!! => C++23���� �߿�
	std::cout << static_cast<Base&>(d).value << std::endl;
			// d�� Baseó�� ���� value ���� -> ���� ��ü ���� X
			// -> class slicing
	std::cout << static_cast<Base>(d).value << std::endl;
			//  => (�߿�) d�� �Ӹ��� �ִ� Base �����ؼ� �ӽ� ��ü ����
			//  ���� ������ ȣ��ȴ�.
}

// �ٽ�
// 1. �ӽ� ��ü�� ����ڰ� �ǵ������� ����.
//		�ַ� �Լ� ���� -> draw_box(Point(1,2), Point(2,3))
// 2. �� ��ȯ �Լ�, �� ĳ���ÿ��� �ӽ� ��ü ����
//		

