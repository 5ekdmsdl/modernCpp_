// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �������� for ��
	for (int i = 0; i < v.size(); i++) {

	}

	// C11���� range for�� ����
	for (auto e : v) {

	}

	// ��ü ���� �Ϻ��� �� ������
	// 2ĭ�� �����Ѱ���
	// �Ųٷ� �� �� ������
	// => ��� C20�������� ����, �ٵ� �������� �ȵ�
	//for (auto e : std::views::reverse(v)) {
	//for (auto e : std::views::take(v,3)) {
	for (auto e : std::views::take(std::views::reverse(v),3)) {
		std::cout << e << std::endl;
	}

}















