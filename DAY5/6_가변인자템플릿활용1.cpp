#include <iostream>

int f(int a, double b) { return 0; }

template<typename T> void foo(T& a) 
{
	typename result<T>::type n;  

	cout << typeid(n).name() << endl; 
}

int main()
{
	foo(f);
}