// std::move()소개
#include <iostream>

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

	// 복사 생성자 ( copy constructor )
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	// 이동 생성자 ( move constructor )
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// c1 인 value,		복사 생성자 호출
	Cat c3 = foo();	// 반환객체:임시객체(rvalue) -> 이동생성자 호출
	Cat c4 = static_cast<Cat&&>(c2);
					// lvalue 인 c2를 rvalue로 캐스팅했으니
					// 이동 생성자 호출, c2 자원은 모두 c4로
	Cat c5 = std::move(c2);
	// std::move()
	// 1. **std::move 자체가 자원을 이동하는 것 X**
	// 2. **rvalue로 캐스팅해주는 게 끝!!!**
	// 3. 캐스팅의 결과 : Cat의 이동생성자 호출 (복사 X)
	// 4. Cat의 이동생성자에서 자원 이동

	std::string s1 = "aaa";
	std::string s2 = std::move(s1);
		// 여기서도 s1 -> rvalue casting -> 이동 생성자
	// 즉, move는 클래스 설계자가 책임져야!!!

	// copy ellision
	// 최적화를 위해 임시 객체 생성 X.
	// 복사(이동) 생성자의 호출 제거
	// 최적화 기법이지만. Cpp17부터 공식 문법임.
	// 
	// => 
	// 
	// 
	//




}




