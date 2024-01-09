// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	auto a = r; // 

	decltype(n) d1; // 
	decltype(r) d2; // 
	decltype(c) d3; // 
	decltype(p) d4; // 
}