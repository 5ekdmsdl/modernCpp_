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

	// 위 for문 컴파일러가 아래처럼 바꿈
	// 결국 아래코드랑 성능이 똑같음.!
	// https://cppinsights.io/ 로 컴파일러의 마음을 알 수 있다.
	auto first = v.begin();
	auto last = v.end();
	
	for (;first != last;first++) {
		auto& n = *first;
		std::cout << n << std::endl;
	}
}















