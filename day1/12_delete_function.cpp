// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// [�����Ϸ� �ڵ� ���� ���] (����ڰ� �ϳ��� �ȸ����...)
	// = ** Special Member Function **
	// ������, �Ҹ���, ���������, ���Կ�����
	// �̵�������, �̵����Կ����� 

	// Cpp11 : �ٵ� �ʿ������ delete ����.
	Point(const Point&) = delete;
	// cpp98 : �׶��׽���... �ذ���, private + ����!
private:
	Point(const Point&);
	
};

int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // �����Ϸ��� ������ִ� ��������ڻ��
}