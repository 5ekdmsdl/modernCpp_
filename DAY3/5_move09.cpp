#include <iostream>
#include <string>

// rule of 0
// => 복사, 이동 아무것도 만들지 않으면 컴파일러가 모두 지원한다.
// => 자원 관리 STL에 의존하라. 
// char*	=> std::string
// int*		=> std::vector, std::shared_ptr

class Cat
{
	std::string name;
	int   age;
public:
	Cat(std::string& n, int a) : name(n), age(a) { }
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
	c2 = c1;

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




