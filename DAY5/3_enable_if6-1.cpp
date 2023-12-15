#include <iostream>
#include <string>
#include <type_traits>


int main()
{
	std::string s1;

	// 아래 코드에 대해 생각...
	s1 = 65;					// ok
	std::string s2 = 65;		// 생성할때는 error!

	std::cout << std::is_convertible_v<int, std::string> << std::endl;
							// false
							// int로 string 만들 수 X

}