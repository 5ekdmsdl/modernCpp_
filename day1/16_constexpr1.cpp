// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10;
	const int c2 = n;

	// ������ ������ ��� ������
	int arr1[10];	// ok
	//int arr2[n];	// error 
	int arr3[c1];	// ok (compiler�� ������ Ÿ�ӿ� ���� �˰� ����.)
	//int arr4[c2];	// error

	// const �ǹ� : ���� ������ �� ����.
	//				�ʱⰪ ������ �ð��� �˼���~ �𸦼���~
	// ** C#, Rust������ ��� X -> immutable, readonly

	// C#,swift, rust������
	// read only, immutable : �� ���� X
	// constant : ������ Ÿ�ӿ� �� �� �ִ� ��
}

// ���� : �迭 ũ��
// g++�� ���� ��밡��, vs�� �Ұ���
