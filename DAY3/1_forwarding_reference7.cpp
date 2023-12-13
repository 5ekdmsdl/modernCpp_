struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// lvalue & rvalue ��� ���� �� �ִ� �Լ� �����

// ��� 1. call by value
//	���纻 ����
void foo(Point pt) {}

// ��� 2. call by const lvalue reference
//	���纻 X, but ����� �߰�
void foo(const Point& pt) {}

// Cpp11===========================
// ��� 3.lvalue, rvalue ���� ���� ����
// ���纻 X, ����� X, 
void foo(Point& pt) {}
void foo(Point&& pt) {}

// ��� 4. forwarding reference
// T&&�� ����ϸ� ���� 2�� �Լ� �ڵ� ����
// ��, Point �Ӹ� �ƴ϶� ��� Ÿ�Կ� ���� ��� ����.
template<typename T>
void foo(T&& pt) {}



int main()
{
	Point pt(0, 0);

	// foo �Լ��� lvalue �� rvalue(�ӽð�ü)�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point(0,0));
}
