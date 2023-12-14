#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	// setter �����.

	void set_name(const std::string& n) { name = n; }


};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1�� �ڿ��� ����. s1�� ��� ����ϰڴٴ� �ǵ�
	p.set_name(std::move(s2));	// s2�� �ڿ��� �̵�. s2�� ���̻� ������� �ʰڴٴ� �ǵ�

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}








