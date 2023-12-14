#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	int age;
public:
	// 1. retain parameter
	// 인자를 멤버 변수로 보관하는 경우만 (Setter, Retainer)
	// move 지원 필요
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }

	// 2. in parameter, not retain
	// 받은 인자를 멤버로 보관X, 그냥 사용만
	// => move 사용할 이유 전혀 X
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}
};

int main()
{
	std::string n = "kim";
	std::string s = "hello";

	People p;
	p.set_name(std::move(n));
	p.print_msg(s);
	p.print_msg(std::move(s));	// 에러는 아니지만 자원 뺏기지X


	//------------------
	// STL 컨테이너들은 push_xxx() 함수가 모두 move 버전도 지원합니다.
	std::vector<std::string> v;

	v.push_back(s);
	v.push_back(std::move(s));
}








