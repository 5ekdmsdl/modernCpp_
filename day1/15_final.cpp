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
	// final : ���̻� ������ X
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

// final ���� : lib ���ο��� ��� ����� �ϰ� ������, 
// ����ڰ� ������ ���� �ʾ����� ���پ�

int main() {
	Derived2 d;
	d.foo();
}