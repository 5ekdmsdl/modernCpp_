// 1_�ʱ�ȭ6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };		// direct reset
	int n2 = { 0 };		// copy reset
	int n3;				// default reset -> ����������� �����Ⱚ
	int n4{};			// value reset - {} �ȿ� ���� ����.
						// => primitive Ÿ���� 0���� �ʱ�ȭ
						// => user define type�� ����Ʈ ������

	std::cout << n4 << std::endl; // 0

	Point pt{};			// ��� ��� 0���� �ʱ�ȭ
						// ��, �����Ϸ��� ���� �����ڿ�����
						// ����� ���� default ������ ���� 
	std::cout << pt.x << std::endl;
}


