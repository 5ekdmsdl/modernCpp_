// 91 page
int main()
{
	int n = 10;

	// #1. �����ʹ� "���� ������"�� ���� �� �ִ�.
	int *p = &n;
	int* *pp = &p;

	// #2. reference�� ���� X
	int& r = n;
	int& &rr = r;		// error

	// #3. Ÿ�� �߷�, �Ǵ� using ���� �߻��ϴ�
	//	���۷����� ���۷����� �Ʒ� ��Ģ ���
	using LREF = int&; 
	using RREF = int&&;

	// (�ܿ��!) reference collapsing ��Ģ 
	LREF& r3 = ? ;	// int& & -> int&
	RREF& r4 = ? ;	// int&& & -> int&
	LREF&& r5 = ? ;	// int& && -> int&
	RREF&& r6 = ?;	// int&& && -> int&&
	// && + && �ϋ����� ��� &&!

	// �Ʒ� foo�� �����غ�����.
	foo<int&>(n);

	int x[3] = { 1,2,3 };
	decltype(x[0])& r;	// int& & r -> int& r
}

template<typename T> void foo(T a)
{
	T& r = a;		// int& & r = a;
					// => int& r = a;
}





