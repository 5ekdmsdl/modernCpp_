#include <iostream>
#include <string>
#include <type_traits>


int main()
{
	std::string s1;

	// �Ʒ� �ڵ忡 ���� ����...
	s1 = 65;					// ok
	std::string s2 = 65;		// �����Ҷ��� error!

	std::cout << std::is_convertible_v<int, std::string> << std::endl;
							// false
							// int�� string ���� �� X

}