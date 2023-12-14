// 6_����_��������ĸ��1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. ����ǥ���Ŀ��� ��������
	auto f1 = [](int a) { return a + g; };
	
	// 2. ����ǥ���Ŀ��� �������� ����
	//auto f2 = [](int a) { return a + v1 + v2; };
	
	// 3. ����ǥ���Ŀ��� �������� �����Ϸ��� ���� ���� ĸ�� �ؾ�
	auto f2 = [v1, v2](int a) { return a + v1 + v2; };

	// 4. ĸ�ĵ� ���� ���� ����
	// => mutable ���ٴ� ����
	auto f3 = [v1, v2](int a) { v1 = 10; return v1 };	// error
	

}





