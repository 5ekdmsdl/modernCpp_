// QA
// nasm �� �н��ϴ°� �����ϴ�.
// 1. windows �� linux, osx ��� ����
// 2. intel ����� ���� ����, godbolt.org ������ ���� ����
// 3. ���� ����, �ڷ� �����ϴ�.
// 4. "nasm tutorial"

// �Լ��� Ŭ����(����ü)
// # �Լ� : ����
void foo()
{
	// ...
}

// # Ŭ���� :	�����Ϸ��� �����ϴ� Ÿ�� 
//				����Լ����� ����� ���� -> assembly���� class ���� �κ��� X
class Point
{
	int x;
	int y;
public:
	void set(int a, int b)
	{
	}
};

int main()
{
	Point pt;			// ���ÿ� 8����Ʈ �Ҵ��ϴ� ����
						// sub rbp, 8

	pt.x = 10;			// pt �ּ� ���κ��� �޸� = 10
	pt.set(10, 20);		// call Point::set(&pt, 10, 20)
}







