       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // ȣ��. ���ڸ� ��ӵ� ��ҿ� �ְ�, 
						 // Add1 �� ��ġ�� �̵�
	int n2 = Add2(1, 2); // ġȯ. ��⿡ Add2�� ���� �ڵ�� ��ȯ
						 // ������!

	int(*f)(int, int) = &Add2;

	// if( user_input == 1) f = &Add1;
	// ������ Ÿ�ӿ� f�� �������� �� �� X

	f(1, 2); // inline ġȯ -> ȣ��!!
}

// 1. �ζ��� ġȯ : "������ �ð�"�� ����
// 2. �ζ��� �Լ��� �Լ� �����Ϳ� �־ ȣ���ϸ� �ζ��� ġȯ X



