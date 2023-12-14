#include <iostream>

int f(int, double, char) { return 0; }



template<typename T> void foo(T& t)
{
	typename argument<1, T>::type n;

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}