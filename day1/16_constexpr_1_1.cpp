// 16_constexpr1
int main()
{
	int n = 10;
	// const : readonly �����
	const int c1 = 10;
	const int c2 = n;

	// Cpp11 constexpr : �� ������ Ÿ�ӿ� �� �� �ִ� ��� �����
	constexpr int c3 = 10;
	constexpr int c4 = n;	// error!

	// readonly�� Cpp ���� ��� "constant expression"
}
