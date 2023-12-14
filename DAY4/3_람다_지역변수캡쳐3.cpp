// 6_����_��������ĸ��1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. ���� ǥ������ ����� Ŭ������ operator() : ��� ��� �Լ�
	//     => �׷��� "v1 = 100" error
	auto f2 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; };
	// ���� ǥ�������� ����� �Լ� = ��� �Լ� -> �� �� �ٲ�...

	// #2. mutable ���ٴ� operator() ��� �Լ� X
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };
	f1(0);		// ���⼭ v1 = 100; ��������� 
				// main�� �������� X, f1 ��ü�� ���纻�� �����Ѱ�


	// =======================================================
	// ���ٽ��� ���� �����Ϸ��� ����� ��ü�� �Ʒ� ����...

	class CompilerGeneratedName {
		// ���� ���� ĸó -> ��� ������ �߰�
		int v1;
		int v2;

	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a) const {
			v1 = 100;
			return a + v1 + v2;
		}
	};

	auto f1 = CompilerGeneratedName(v1, v2);


}







