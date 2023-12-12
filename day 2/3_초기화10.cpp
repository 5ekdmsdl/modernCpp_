// 1_초기화10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 2);		// vector(std::size_t, int)
	std::vector<int> v4{10, 2};		// vector(std::initializer_list<int>)


	// 아래 코드에서 에러는 ?
	std::vector<int> v5 = 10;		// error explicit vector(int)
	std::vector<int> v6 = {10};		// ok, vector(std::init_list<int>) explicit X
									// 복사 초기화 가능
}




