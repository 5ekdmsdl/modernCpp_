#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// ����Ʈ ������
	// 1. ���� ��ü ����
	//	  �Ʒ� �ڵ�� ���� �޸𸮸� ��� �Ҵ� �ұ�� ?
	// => new Point ������ 1ȸ ȣ��
	// => spointer control block ����鼭 1ȸ ȣ��
	std::shared_ptr<Point> sp1(new Point(1,2));

	// 2. std::make_shared
	// => Point ��ü�� control block�� �ٿ��� �ѹ��� �Ҵ� -> �޸� ȿ�� ��
	// => new Point������ X
	//		���̺귯�� ���ο��� "sizeof(Point) + sizeof(control block)" �ѹ��� �Ҵ��ؾ�
	
	std::shared_ptr<Point> sp = std::make_shared<Point>(1,2);
	// => sizeof(Point) + sizeof(control block) �ѹ��� �Ҵ�
	// => ���ڷ� ���޵� 1,2�� Point �����ڷ� "�Ϻ� ����"
	// => �ش� �޸� �����ϴ� shared pointer �����ϰ�, return
}

// main						make_shared				Point(int a, int b)
// (1, 2) ===================> ���� ���ڸ� �ٽ� =========> �̰����� ����






