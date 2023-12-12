// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);
	// T a = 10;	// �Ʒ� auto �ڵ�� ����
	auto a = 10;	// auto �߷� == ���ø� �߷� (����)

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	// auto -> ��Ģ 1. ������ ������
	// const, volatile, refer ��� ����
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// auto& -> ��Ģ 2. �캯�� ref�� ����
	auto& a5 = n;  // auto : int        a5 : int&
	auto& a6 = r;  // auto : int	    a5 : int&
	auto& a7 = c;  // auto : const int  a5 : const int&
	auto& a8 = cr; // auto : const int  a5 : const int&

	
	int x[3] = { 1,2,3 };

	// x : int[3]
	auto  a11 = x;	// �迭�� ���� -> �迭 ����X
					// => auto : �迭 pointer
					// auto int* a11 = x;
	auto& a12 = x;	// ���� => auto : �迭
					// int(&)[3] a12 = x;
}


