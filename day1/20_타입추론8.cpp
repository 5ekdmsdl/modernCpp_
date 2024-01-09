int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	auto a = x[0];
	decltype(x[0]) d; 
}

