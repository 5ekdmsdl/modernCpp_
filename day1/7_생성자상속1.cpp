// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};

// 생성자는 상속되지 X
class Derived : public Base
{
public:
	//C11 부터는 생성자 상속 가능
	// => using 클래스이름::생성자이름 
	using Base::Base;
	// Base(), Base(int) 모두 상속되는 것
	
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
