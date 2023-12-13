#include <iostream>

// rule of 5, 3
// 1. 생성자에서 자원 할당 코드 있으면
//	=> 소멸자, 복사 생성자, 대입 연산자 만들어라!
//  => rule of 3
// 
// 2. Cpp 11 이후에는 이동 생성자, 이동 대입 생성자도 만들어라
// => rule of 5
// 
// 
//


class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}
	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}

	// 복삿 생성자 만들면, 대입 연산자도 만들어야
	Cat& operator=(const Cat& c) {
		// 자신과의 대입을 조사 -> 아무일도 안일어나도록
		if (&c == this) return *this;

		age = c.age;
		delete[] name;
		strcpy_s(name, strlen(c.name) + 1, c.name);
		return *this;
	}


	// 이동 생성자 -> 이동 대입 연산자 만들어야
	Cat& operator=(Cat&& c) {
		if (&c == this) return *this;

		age = c.age;
		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
	}

	
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;   
	c2 = c1;

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




