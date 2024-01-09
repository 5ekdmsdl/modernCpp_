// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept Ű����� 2���� �뵵
// 1. ǥ���Ŀ� ���� �˻�
//    => bool b = noexpcept(expression)
//    => �Լ� ���� ��ü ���� X, �Լ� ���� noexcept �ִ����� Ȯ��
// 
// 2. �Լ��� ���� ����/���� �˸���

void foo()          // ���� ���ɼ� �ִ� �Լ�  
{
}

void goo() noexcept	// ���� ���ɼ� ���� �Լ�
{
}

int main()
{
	bool b1 = noexcept(foo());
	// ���� ���ɼ� �ֱ� ������ b1 = false
	bool b2 = noexcept(goo());
	// goo�� noexcpet�ϱ� b2 = true

	std::cout << "b1" << "," << b2 << std::endl;
}

// move �Ҷ� noexcept Ȱ�� ����!







