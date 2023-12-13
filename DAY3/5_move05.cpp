// std::move()�Ұ�
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

	// ���� ������ ( copy constructor )
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}

	// �̵� ������ ( move constructor )
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
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

	Cat c2 = c1;	// c1 �� value,		���� ������ ȣ��
	Cat c3 = foo();	// ��ȯ��ü:�ӽð�ü(rvalue) -> �̵������� ȣ��
	Cat c4 = static_cast<Cat&&>(c2);
					// lvalue �� c2�� rvalue�� ĳ����������
					// �̵� ������ ȣ��, c2 �ڿ��� ��� c4��
	Cat c5 = std::move(c2);
	// std::move()
	// 1. **std::move ��ü�� �ڿ��� �̵��ϴ� �� X**
	// 2. **rvalue�� ĳ�������ִ� �� ��!!!**
	// 3. ĳ������ ��� : Cat�� �̵������� ȣ�� (���� X)
	// 4. Cat�� �̵������ڿ��� �ڿ� �̵�

	std::string s1 = "aaa";
	std::string s2 = std::move(s1);
		// ���⼭�� s1 -> rvalue casting -> �̵� ������
	// ��, move�� Ŭ���� �����ڰ� å������!!!

	// copy ellision
	// ����ȭ�� ���� �ӽ� ��ü ���� X.
	// ����(�̵�) �������� ȣ�� ����
	// ����ȭ ���������. Cpp17���� ���� ������.
	// 
	// => 
	// 
	// 
	//




}




