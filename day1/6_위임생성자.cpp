#include <iostream>
// 6_위임생성자 - 24page
// delegating constructor
class Point
{
public:
	int x, y;
public:
	// C11 부터는 위임 생성자 -> 생성자 내에 다른 생성자 호출 가능
	Point() : Point(0,0) {
		// C98에서는 생성자내에서 다른 생성자 호출 X
		// => 이렇게 하면 생성자안에서 임시 객체를 또 만드는 것임.
		//Point(0, 0);
	}
	Point(int a, int b) : x(a), y(b) {
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

