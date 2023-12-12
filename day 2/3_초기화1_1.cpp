// 초기화 - 55 page
#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;
	int value2 = ++x;			// 너어무 나쁜 코드!!!
public:	
	Test() {}					// Test()  : value1(0), value2(++x)
	Test(int n) : value2(n) {}	// Test(n) : value1(0), value2(n)
};

int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 예측해보세요. ?
	// 11...?

}