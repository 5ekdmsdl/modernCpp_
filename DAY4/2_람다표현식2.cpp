// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// ����ǥ������ ����!
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	//=======================================================
	// �� �ڵ带 �����Ϸ��� �Ʒ�ó�� �����մϴ�.
	
	//class CompilerGeneratedName	// ���� ǥ������ ����� Ŭ���� �̸� : �����Ϸ��� ���Ƿ� ����
	class ClosureType				// �Ϲ������� �������� �� �̸� ���
	{								// Closure�� ����� type�̶�� �ǹ�.
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

	// ������ ���� ��� = �ᱹ "�ӽ� ��ü"
	// lambda expression���� "expression"�� �ϳ��� ������ ���Ǵ� �ڵ� !
	// => �Լ� ��ü�� �ӽ� ��ü ���·� ������ ��
	// => �ᱹ, "Ŭ����" ���� ��
	// => cppreference.com�� 1���� ȭ�鿡�� expression ����
	//  ���� �߰��� "lambda expression" ���� -> 1��° ���� �б�



}





