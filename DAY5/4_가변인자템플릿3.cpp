#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

void incr(int& a) { ++a; }

template<typename ... Types> 
void foo(Types ... args)
{
	// #1. pack expansion ���� �˾ƾ�
	// "pack�̸�..."			=> E1 E2 E3
	// "pack������ϴ��ڵ�..."	=> E1����ڵ�, E2����ڵ�, E3����ڵ�

	goo(args...);			// goo(1,2,3)
	goo(args++...);			// goo(1++, 2++, 3++)

	// �Ʒ� 2���� ������ 
	goo(hoo(args...));		// goo(hoo(1,2,3))				-> compile error
	goo(hoo(args)...);		// goo(hoo(1), hoo(2), hoo(3))	-> ok


}


int main()
{
	foo(1, 2, 3);
}

