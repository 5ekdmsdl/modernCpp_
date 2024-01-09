// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	for (auto& n : v) 
	{
		std::cout << n << std::endl;
	}

	// �� for�� �����Ϸ��� �Ʒ�ó�� �ٲ�
	// �ᱹ �Ʒ��ڵ�� ������ �Ȱ���.!
	// https://cppinsights.io/ �� �����Ϸ��� ������ �� �� �ִ�.
	auto first = v.begin();
	auto last = v.end();
	
	for (;first != last;first++) {
		auto& n = *first;
		std::cout << n << std::endl;
	}
}














