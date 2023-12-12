int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// #1. auto vs decltype
	auto a = x[0];			// int a = x[0]
	decltype(x[0]) d;		// int& d

	// #2. 
	auto ret1 = foo;		// foo() ��ȯŸ�� int& -> auto : int
	// decltype(�Լ� ȣ���) : �Լ� ��ȯ Ÿ��, �Լ� ���𺸰� ����
	decltype(foo()) ret2 = foo();  // int& ret2 = foo();
	// decltype ���� �Լ��� ������ Ÿ�ӿ� �ٲ�� -> ȣ�� X

	// #3. decltype(auto) : C++14���� ����
	// => auto �ڸ��� �캯 ���ƶ�.
	// => �캯���� Ÿ�� �߷� -> ��Ģ�� decltype���� �϶�.
	decltype(auto) ret3 = foo();
	
	// ret1 : int ����, 
	// ret 2,3 int& -> X�� ����
}

