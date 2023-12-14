// ���� ǥ������ �Լ� �����Ϳ� ���� ��
// ==> ���� �����غ���...
#include <iostream>
class ClosureType
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// static ��� �Լ��� ��ü ���� ȣ�� -> this ���� ȣ�� ����
	// �Լ� ǥ���ͷ��� ��ȯ ���� operator() �Ȱ��� static ��� �Լ� ����
	static int helper(int a, int b) { return a + b; }

	// �Լ� �����ͷ��� ��ȯ�� ���� ��ȯ ������ �߰��ȴ�.
	using PF = int(*)(int, int);
	operator PF() { return &ClosureType::helper; }
					// error
					// �Ϲ� �Լ� �����Ϳ� ��� �Լ� �ּ� ���� �� X
};

int main()
{
	//int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = ClosureType();
						// �ӽð�ü.operator �Լ�������Ÿ��();

	int n = f(1, 2);
	
	std::cout << n << std::endl;	// 3

}












