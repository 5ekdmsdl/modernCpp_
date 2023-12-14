#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// setter 만들기.

	void set_name(const std::string& n) { name = n; }


};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1의 자원을 복사. s1은 계속 사용하겠다는 의도
	p.set_name(std::move(s2));	// s2의 자원을 이동. s2는 더이상 사용하지 않겠다는 의도

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}








