// 1_�ʱ�ȭ10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// �Ʒ� 2���� �������� ?
	std::vector<int> v3(10, 2);		// vector(std::size_t, int)
	std::vector<int> v4{10, 2};		// vector(std::initializer_list<int>)


	// �Ʒ� �ڵ忡�� ������ ?
	std::vector<int> v5 = 10;		// error explicit vector(int)
	std::vector<int> v6 = {10};		// ok, vector(std::init_list<int>) explicit X
									// ���� �ʱ�ȭ ����
}




