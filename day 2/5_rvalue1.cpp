// 4_rvalue - 87 page
int x = 0;
int  foo() {	return x;}
int& goo() { return x; }

int main()
{
	int v1 = 10, v2 = 10;
	v1 = 20;
	10 = v1;
	v2 = v1;
	int* p1 = &v1;
	int* p2 = &10; 
}









