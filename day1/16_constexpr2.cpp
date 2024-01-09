// constexpr function
// 1. ���� ���� ������ �ð��� �� �� �ְ�,
// 2. ������ �ð��� ���� �˾ƾ��ϴ� ��ġ���
// => �Լ� ������ �������Ҷ� �����϶�!!

constexpr int Factorial(int n)
{
	// �� �޸� �Ҵ� �� ��Ÿ���� �ʿ��� ���۵��� X
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)];		// ok ������ �ϸ� int arr1[120]

	int arr2[Factorial(n)];		// error, ������ Ÿ�ӿ� �� �� X


	int s = Factorial(5);		// ok, ���� �ð��� ����

	int s2 = Factorial(n);		// ������ �ð� vs ���� �ð� 
								// -> �����Ϸ����� �ٸ� �� (ǥ�� ���� X)

	const int s3 = Factorial(5);		// �ֵ� �����Ϸ� ���� �ٸ� ��,,,
	
	constexpr int s4 = Factorial(5);	// ������ �ð�! constexpr�̴ϱ�



}