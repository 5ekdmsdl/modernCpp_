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
	//// MyList가 std::list와 동일하게 사용하려면 **생성자** 필요
	
	// #1. C++98 -> 직접 똑같이 전달하는 생성자 만든다
	// ex) MyList(int sz) : std::list<int>(int sz) {]
	
	// #2. C+11 생성자 상속 사용
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




