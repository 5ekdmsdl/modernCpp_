#include <iostream>

template<typename T> void foo(T args)
{

}

int main()
{
	foo(1, 3.4, 'A');
	foo(1, 2, 3);
}