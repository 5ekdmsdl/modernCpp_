// 1_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
	Point pt(1, 2);		// named object
						// ���� : �ڽ��� ������ ���� ����� �ı�

	Point(1, 2);		// ���� ������ �ڵ忡�� "��ü �̸��� ����"
						// => �̸� ���� ��ü = �ӽ� ��ü (temperary)
						// ���� : {}�� �ƴ� ������ ��

	Point(1, 2), std::cout << "x" << std::endl;	// �� ���� ������ �Ҹ�

	std::cout << "-------" << std::endl;
}

// python, Rust���� �ӽ� ��ü ���� ����!





