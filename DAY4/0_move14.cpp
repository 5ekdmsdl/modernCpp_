#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #3

class People
{
private:
	std::string name;
	int age;
public:
	// 1. retain parameter
	// ���ڸ� ��� ������ �����ϴ� ��츸 (Setter, Retainer)
	// move ���� �ʿ�
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }

	// 2. in parameter, not retain
	// ���� ���ڸ� ����� ����X, �׳� ��븸
	// => move ����� ���� ���� X
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
	p.print_msg(std::move(s));	// ������ �ƴ����� �ڿ� ������X


	//------------------
	// STL �����̳ʵ��� push_xxx() �Լ��� ��� move ������ �����մϴ�.
	std::vector<std::string> v;

	v.push_back(s);
	v.push_back(std::move(s));
}








