// 9_enum - 32 page

enum Color {
	red = 1,
	green = 2,
};

void foo(int dayofaweek) {}

int main()
{
	int c1 = Color::red;
	// #1. enum ���� : Color ���� -> ���� ������� �𸣰���.
	int c2 = red;

	int red = 2;
	auto c2 = red;
	// ���⼭ c2�� �� ����� �������� red�� ä�� -> c2 == 2

	// #2. int�� �Ͻ��� ��ȯ�� ������ ���� �ڵ�...	
	int c4 = Color::red;
	c4 = 100;

	// ==> ������ enum�� �ʿ��ϴ�!!

	foo(0);  
}





