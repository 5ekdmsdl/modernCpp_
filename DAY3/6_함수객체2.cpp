#include <iostream>

// ÇÔ¼ö°´Ã¼¿Í const member function

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T> void foo(T f)
{
	int ret = f(1, 2);
}

int main()
{
	Plus p;

	foo(p);
}
