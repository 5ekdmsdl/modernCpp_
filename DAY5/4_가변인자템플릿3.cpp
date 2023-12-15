#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

void incr(int& a) { ++a; }

template<typename ... Types> 
void foo(Types ... args)
{
	// #1. pack expansion 문법 알아야
	// "pack이름..."			=> E1 E2 E3
	// "pack을사용하는코드..."	=> E1사용코드, E2사용코드, E3사용코드

	goo(args...);			// goo(1,2,3)
	goo(args++...);			// goo(1++, 2++, 3++)

	// 아래 2줄의 차이점 
	goo(hoo(args...));		// goo(hoo(1,2,3))				-> compile error
	goo(hoo(args)...);		// goo(hoo(1), hoo(2), hoo(3))	-> ok


}


int main()
{
	foo(1, 2, 3);
}

