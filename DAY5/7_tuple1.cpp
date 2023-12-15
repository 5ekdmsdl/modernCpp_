// 8_tuple1 - 245 page
#include <tuple>
#include <iostream>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	auto a1 = p.first;
	auto a2 = p.second;

	// pair에 2개 이상 보관된다.
	std::pair<int, std::pair<double, char>> p2(1, {3.4, 'A'});

	auto a3 = p2.second.first;	// 3.4

	//============================================================
	// Cpp 11부터 tuple 지원
	// : 서로 다른 타입 N개를 보관 가능
	std::tuple<int, double, char> t(1, 3.4, 'A');

	// 각 요소의 접근은 std::get을 사용
	std::get<0>(t) = 100;
	std::cout << std::get<0>(t) << std::endl;
}


