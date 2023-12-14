// ���� ǥ������ �Լ� �����Ϳ� ���� ��
// ==> ���� �����غ���...
#include <iostream>
class ClosureType
{
	int v1;
	int v2;

public:
	ClosureType(int a, int b) : v1(a), v2(b) {}

	inline int operator()(int a, int b) const { return v1 + v2 + a + b; }

	// static �Լ� -> ��� �Լ� ���� X			=> error!
	static int helper(int a, int b) { return v1 + v2 + a + b; }

	using PF = int(*)(int, int);
	operator PF() { return &ClosureType::helper; }
};

int main()
{
	int v1 = 0; int v2 = 0;

	// ĸ���� ���� ǥ���� : �Լ� ǥ�������� ��ȯ �Ұ�!!
	//   => �Ʒ� �ڵ�� ����!!
	//	 => ĸ������ ���� ���� ǥ���ĸ� �Լ� ������ ��ȯ ����
	//int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = ClosureType();

	int n = f(1, 2);

	std::cout << n << std::endl;	// 3

}












