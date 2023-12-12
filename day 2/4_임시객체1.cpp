// 1_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
	Point pt(1, 2);		// named object
						// 수명 : 자신을 선언한 블럭을 벗어날때 파괴

	Point(1, 2);		// 위와 동일한 코드에서 "객체 이름만 제거"
						// => 이름 없는 객체 = 임시 객체 (temperary)
						// 수명 : {}이 아닌 문장의 끝

	Point(1, 2), std::cout << "x" << std::endl;	// 요 문장 끝날때 소멸

	std::cout << "-------" << std::endl;
}

// python, Rust에도 임시 객체 개념 존재!





