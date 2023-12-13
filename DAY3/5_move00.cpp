// ��������� ����� ������ ���ô�.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// �����Ϸ��� ����� ���� �������� ��Ȯ�� ���
	// #1. call by value
	//	Point p3(p2) ���� p2�� ���޵ɶ� �� ���� ������ ȣ��
	//	������ ����!
	Point(const Point& other) : x(other.x), y(other.y) {}

	// #2. call by non-const (lvalue) reference
	// ���� X , �ٵ� rvalue ���� �� ����.
	// Point ret = foo(); <- ����!
	Point(Point& other) : x(other.x), y(other.y) {}
	
	// #3. call by const (lvalue) reference
	// C98 ���� �����ѹ��
	Point(const Point& other) : x(other.x), y(other.y) {}

};

int main()
{
	Point p1;		// 1�� ������
	Point p2(1, 2); // 2�� ������
	Point p3(p2);	// Point ���� ������ �ʿ� -> �����Ϸ��� �ۼ�	

	Point ret = foo();	// ���� ������ ���ڰ� Point& �� ����!
}




