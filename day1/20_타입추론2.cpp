#include <iostream>

template<typename T> void foo(T a)
{
	a = 100;
}
int main()
{
	// T의 타입을 예측해 보세요
	foo(10); // T : 
	foo(3.4);// T : ?

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n); 
	foo(c); 
	foo(r); 
	foo(cr);
}