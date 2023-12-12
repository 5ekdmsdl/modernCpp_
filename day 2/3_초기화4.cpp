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
	Vector v1(10);			// Cpp98, direct init
	Vector v2 = 10;			// Cpp98, copy init
	Vector v3{ 10 };		// Cpp11, direct init + uniform
	Vector v4 = { 10 };		// Cpp11, copy init + uniform

	//----------------
	// #2. 
	foo(10); // �Լ� ���� ���� copy init
			 // Vector v = 10
				// ���� �ʱ�ȭ�� ���� -> explicit �������.
}







