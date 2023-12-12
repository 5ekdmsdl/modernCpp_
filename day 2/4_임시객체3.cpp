// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}
void reset(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	//Point pt(1, 2);
	//Point pt2(5, 5);
	//draw_line(pt, pt2);		// ok, 근데 p1, p2는 소멸X

	// 함수 인자로만 사용되는 경우, 임시 객체 사용 권장
	draw_line(Point(1, 2), Point(5, 5));
	draw_line({ 1,2 }, { 5,5 });			// 중괄호 초기화 (Cpp11 부터)
	//================================================

	Point pt(1, 1);
	reset(pt);
	reset(Point(1, 1));		// 임시 객체의 값을 바꿀게
							// -> error
							// 임시객체는 const로만 인자 전달 가능!

	std::cout << "-----" << std::endl;
}
// 참고
// 인자 1개 생성ㅇ자 -> explicit 일반적
// 인자 여러개 생성자 -> explicit 가능, 근데 많이 쓰지 X




