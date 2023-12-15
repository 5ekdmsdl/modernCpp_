// 8_tuple1 - 245 page
#include <tuple>
#include <iostream>

int main()
{
	// pair : ���� �ٸ� Ÿ�� 2���� ���� - C++98
	std::pair<int, double> p(1, 2.3);

	auto a1 = p.first;
	auto a2 = p.second;

	// pair�� 2�� �̻� �����ȴ�.
	std::pair<int, std::pair<double, char>> p2(1, {3.4, 'A'});

	auto a3 = p2.second.first;	// 3.4

	//============================================================
	// Cpp 11���� tuple ����
	// : ���� �ٸ� Ÿ�� N���� ���� ����
	std::tuple<int, double, char> t(1, 3.4, 'A');

	// �� ����� ������ std::get�� ���
	std::get<0>(t) = 100;
	std::cout << std::get<0>(t) << std::endl;
}


