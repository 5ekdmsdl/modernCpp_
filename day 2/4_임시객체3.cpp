// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� �Լ� ���� - 81 page
void draw_line(const Point& from, const Point& to) {}
void reset(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	//Point pt(1, 2);
	//Point pt2(5, 5);
	//draw_line(pt, pt2);		// ok, �ٵ� p1, p2�� �Ҹ�X

	// �Լ� ���ڷθ� ���Ǵ� ���, �ӽ� ��ü ��� ����
	draw_line(Point(1, 2), Point(5, 5));
	draw_line({ 1,2 }, { 5,5 });			// �߰�ȣ �ʱ�ȭ (Cpp11 ����)
	//================================================

	Point pt(1, 1);
	reset(pt);
	reset(Point(1, 1));		// �ӽ� ��ü�� ���� �ٲܰ�
							// -> error
							// �ӽð�ü�� const�θ� ���� ���� ����!

	std::cout << "-----" << std::endl;
}
// ����
// ���� 1�� �������� -> explicit �Ϲ���
// ���� ������ ������ -> explicit ����, �ٵ� ���� ���� X




