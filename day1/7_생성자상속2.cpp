#include <list>
#include <iostream>

class MyList : public std::list<int>
{
public:
	void print() const {
		for (auto e : *this) {
			std::cout << e << std::endl;
		}
	}
	//// MyList�� std::list�� �����ϰ� ����Ϸ��� **������** �ʿ�
	
	// #1. C++98 -> ���� �Ȱ��� �����ϴ� ������ �����
	// ex) MyList(int sz) : std::list<int>(int sz) {]
	
	// #2. C+11 ������ ��� ���
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);
}




