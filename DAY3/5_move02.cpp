#include <iostream>
#include <string>
#include <vector>

// �� move�� �߿��Ѱ� ? - 101 page �Ʒ� �ֽ��ϴ�.

// �Ʒ� �ڵ�� "����" ��� swap -> Cpp98 ���� C++ ǥ�� ����
// => ���� ���� �ʴ�!
template<typename T>
void Swap(T& a, T& b) {
	T tmp = a;		// ���� ������ �ܶ� ȣ��
	a = b;
	b = tmp;
}

// Cpp 11���� swap ����
// �̵��� ����� swap -> ���� �������� �κ��� (string �̸� ��)
template<typename T>
void Swap(T& a, T& b) {
	T tmp = std::move(a);		// ���� ������ �ܶ� ȣ��
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move ��� �������� �˾ƾ��ϴ� ��
// 1. swap �˰��� �ۼ���, std::move ����ϸ� ���� ���
// 2. std::string ���� ǥ�� ���̺귯�� ����,
//		����� define class ������ ��� �ؾ��ϳ�



