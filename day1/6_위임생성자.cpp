#include <iostream>
// 6_���ӻ����� - 24page
// delegating constructor
class Point
{
public:
	int x, y;
public:
	// C11 ���ʹ� ���� ������ -> ������ ���� �ٸ� ������ ȣ�� ����
	Point() : Point(0,0) {
		// C98������ �����ڳ����� �ٸ� ������ ȣ�� X
		// => �̷��� �ϸ� �����ھȿ��� �ӽ� ��ü�� �� ����� ����.
		//Point(0, 0);
	}
	Point(int a, int b) : x(a), y(b) {
		// ������ �ʱ�ȭ �ڵ�
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

