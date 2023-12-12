#include <iostream>
// 85 page
struct Base
{
	int value = 10; // c++11 부터 이렇게 초기화가능
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl; 

}

