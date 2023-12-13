// T& : ��� Ÿ��(����Ÿ��)�� lvalue �� ������ �ִ�.

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// #1. Ÿ�����ڸ� ���������� �����ϴ� ���
	// => �Լ� ���ڸ� ���� T�� �߷��ϴ� ���� �ƴ϶�, ����ڰ� ������ Ÿ�Ի��
	f3<int>(n);		// T = int		T& = int&			f3(int& a) �Լ� ����
	f3<int&>(n);	// T = int&		T& = int& &			f3(int& a) �Լ� ����
	f3<int&&>(n);	// T = int&&	T& = int&& &		f3(int& a) �Լ� ����


	// #2. Ÿ���� ���������� �������� �ʴ� ���
	// => �Լ��� ���ڸ� ����, Ÿ���� �߷�. 
	f3(3);	// 3�� int. T�� int, int&, int&& �� ������� �ص�
			// ������ �Լ��� 3�� ������ ����.
			// �Լ��� ����� �����Ƿ� error.

	f3(n);	// T=int �� �����ؼ�, f3(int& a) �� �Լ� ����
}