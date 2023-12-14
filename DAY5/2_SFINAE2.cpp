#include <iostream>


template<typename T>
int foo(T a)  { std::cout << "T" << std::endl; return 0; }

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(3); 
}