// decltype ��Ģ 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// decltype ��Ģ 1. �ɺ� �̸��� ������
	// �ش� ������ ���� Ÿ��
	decltype(p)		d1; 

	// ��Ģ 2. exp�� "�ɺ� �̸�+ǥ����(������)"
	// exp�� ��ȣ ����(rval)�� �� �� ������ ref Ÿ��
	// �ƴϸ� value Ÿ��
	decltype(*p)	d2;  // *p = 10 ����-> int& d2		(�ʱⰪ error)
	decltype(x[0])	d3;	 // x[0] = 10 ���� -> int& d3

	decltype(n) d;		// n = 10 ����, �ٵ� �ɺ��� ���� 
						// -> �������� ���� -> int d
					

	decltype(n + n) d4;  // n + n = 10 (X) -> int d4
	decltype(++n)   d5;  // ++n = 10 (O)   -> int& d5
						
						
	decltype(n++)   d6;  // n++ = 10 (error) -> int d6
	
	++n = 10;
}

// ���� : ���� �� = �ᱹ���� ����
//int x = 0;
//int  f1() { return x; } // x�� �� 0 ��ȯ
//int& f2() { return x; } // x�� �� 0�� �ƴ� ������ ��ȯ
//
//int main()
//{
//	f1() = 10; // error. 0 = 10 �� �ǹ�.
//	f2() = 10; // ok.    x = 10 �� �ǹ�.
//}

/* ���� : ++n�� n++ ������
// operator++ �� primitive Ÿ�Կ� ���ؼ� overloading �Ҽ� ������, ������ ����
// ������ ++
int& operator++(int& a)
{
	a = a + 1;
	return a;
}
int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}
*/

