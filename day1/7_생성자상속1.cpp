// 7_�����ڻ��1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};

// �����ڴ� ��ӵ��� X
class Derived : public Base
{
public:
	//C11 ���ʹ� ������ ��� ����
	// => using Ŭ�����̸�::�������̸� 
	using Base::Base;
	// Base(), Base(int) ��� ��ӵǴ� ��
	
};

int main()
{
	// �Ʒ� 2���� ������ ������
	Derived d1;
	Derived d2(5);
}
