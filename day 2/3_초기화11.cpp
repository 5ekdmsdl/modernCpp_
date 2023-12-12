// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization
// => ������ ���� { }�� �ʱ�ȭ �Ǵ� ��

//aggregate type
// ������ ���� { } �� �ʱ�ȭ ����
// => �迭, ����ü, ����ü

struct Point
{
	int x, y;

	//Point()             : x(0), y(0) {}	// 1
	//Point(int a, int b) : x(a), y(b) {}	// 2

	//virtual void foo() {} // ���� �Լ� ������ aggregate reset X

	//Point() {}				// ������ ������ agg type X

	Point() = default;		// �����Ϸ��� ����� agg type
};

int main()
{
	Point p1;	
	//Point p2(1, 2);	// error
	Point p3 = { 1,2 };
	// p3�� agg type�� ��쿡�� ���� ���� 
	// -> �����ڸ� �����Ϸ��� ����� ��츸 ����

}