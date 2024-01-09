#include <iostream>

class Base
{
public:
	virtual void foo() {
		std::cout << "B";
	}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// final : 더이상 재정의 X
	virtual void foo()      override final {
		std::cout << "d1";
	} 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

class Derived2 : public Derived
{
public:
	//virtual void foo()      override {}		// error!! 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

// final 목적 : lib 내부에서 상속 허용은 하고 싶은데, 
// 사용자가 재정의 하지 않았으면 좋겟어

int main() {
	Derived2 d;
	d.foo();
}