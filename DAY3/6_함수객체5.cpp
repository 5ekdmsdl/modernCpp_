#include <iostream>
#include <vector>
#include <algorithm>

void show_function(int n)
{
	std::cout << n << std::endl;
}

struct show_function_object
{
	void operator()(int n) const
	{
		std::cout << n << std::endl;
	}
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	std::for_each(v.begin(), v.end(), show_function);
	std::for_each(v.begin(), v.end(), show_function_object() );
}

