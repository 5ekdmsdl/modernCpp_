#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #2

class People
{
private:
	std::string name;
	std::string address;
public:
	// ���ڰ� 2���� setter �� move �����ϱ�.
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
//	p.set(std::move(name), addr);
//	p.set(name,			   std::move(addr));
//	p.set(std::move(name), std::move(addr));
}








