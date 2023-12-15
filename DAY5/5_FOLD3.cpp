#include <iostream>
#include <vector>

template<typename ... Types>
void fn(std::vector<int>& v, Types ... args)
{
	// pack 안의 모든 요소를 v에 넣고 싶다.
	(v.push_back(args), ...);
		// v.push_back(1), (v.push_back(2), (v.push_back(3), ...  
}

int main()
{
	std::vector<int> v;

	fn(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	fn(v, 1, 2, 3, 4, 5);

	for (auto e : v)
		std::cout << e << ", ";
		// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
}

// 이외에도 구글에서 "C++ Fold expression example" 검색하면
// 재미있고, 독특한 예제 볼 수 있다.

