#include <iostream>

template<typename T> void foo(T& a)
{
	a = 100;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  
	foo(c);  
	foo(r);  
	foo(cr); 
}