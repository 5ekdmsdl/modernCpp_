// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++) {

	}

	// C11에서 range for문 제공
	for (auto e : v) {

	}

	// 전체 말고 일부할 수 없나요
	// 2칸씩 가능한가요
	// 거꾸로 할 수 없나요
	// => 모두 C20에서부터 가능, 근데 그전에는 안됨
	//for (auto e : std::views::reverse(v)) {
	//for (auto e : std::views::take(v,3)) {
	for (auto e : std::views::take(std::views::reverse(v),3)) {
		std::cout << e << std::endl;
	}

}















