// 1_�ʱ�ȭ8 - 62page
#include <iostream>
#include <initializer_list> // �ٽ�

void foo(std::initializer_list<int> e) {
}
int main()
{
	// std::initializer_list<int> 
	// -> �ʱⰪ�� �迭�� ������ ������ �޸𸮿� �����,
	// -> �ش� �޸𸮸� ����Ű�� "������ ��" or "�ּ�+����"

	std::initializer_list<int> e = { 1,2,3,4,5 };
	
	// vector ������
	// vector�� �����Ͱ� heap�� ����.
	
	// �迭 ������
	// �迭 ��ü�� �Լ� ���ڷ� ����� �� X

	// ���� ���?
	// => �ַ� ������ ���ڷ� ���

	// ������ STL ó��

	// �Լ����ڷ� initializer_list ���� ���
	foo({ 1,2,3 });
}


