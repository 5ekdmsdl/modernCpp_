// 58 page
class Vector
{
	int sz;
public:
	// explicit ������ : ���� �ʱ�ȭ�� ����
	// main�� copy init�� ��� error
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// #1. ���ڰ� �Ѱ��� �����ڰ� ������ �Ʒ��� ǥ����� �����մϴ�.
	Vector v1(10);			// Cpp98, direct reset
	Vector v2 = 10;			// Cpp98, copy reset
	Vector v3{ 10 };		// Cpp11, direct reset + uniform
	Vector v4 = { 10 };		// Cpp11, copy reset + uniform

	//----------------
	// #2. 
	foo(10); // �Լ� ���� ���� copy reset
			 // Vector v = 10
				// ���� �ʱ�ȭ�� ���� -> explicit �������.
}







