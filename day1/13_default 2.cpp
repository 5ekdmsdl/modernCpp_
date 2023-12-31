// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
public:
	int x, y;

	//Point() {}		
	Point() = default;
};

int main()
{
	Point p{};  // C++11 부터 이런 초기화도 가능( 화~수에 배우게 됩니다)
				// 모든 멤버 0으로 초기화 가능
				// 단, 사용자가 만든 디폴트 생성자 없을때만 

	std::cout << p.x << ", " << p.y << std::endl;
}





