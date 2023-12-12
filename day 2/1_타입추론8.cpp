// decltype Ÿ�� �߷� - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	auto a = r;		// int a = r;
					// auto : ref ����

	// decltype(exp) ��Ģ 1. exp�� �ɺ� �̸��� ������
	// �ɺ��� ���� ����, ���� Ÿ������ ����

	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2			(�ʱⰪ X error)
	decltype(c) d3; // const int d3		(�ʱⰪ X error)
	decltype(p) d4; // int* d4
}