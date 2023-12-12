// member field initialization

//class Point
//{
//	// Cpp11���� ��� ������ �ʱⰪ ���� ��
//	int x = 0;
//	int y = 0;
//public:
//	Point() {}
//	Point(int a) : y(a) {}
//};

// => �����Ϸ� ������ �����
class Point
{
	int x; // = 0;
	int y; // = 0;
public:
	// ��� �ʱⰪ ����, �����Ϸ��� ������ �ٲ�.
	Point()		 : x(0), y(0) {}
	Point(int a) : x(0), y(a) {}
	// �̹� �ʱ�ȭ���� ������ �ƴ� �͸� �߰�
};