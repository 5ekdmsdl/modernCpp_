// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
	// "Ŭ�����̸�::�̸�" ���� �̸���
	// "��" �ϼ���, "Ÿ��" �ϼ��� ����
	Test::data  * p; // data �� -> * : ���ϱ�
	Test::DWORD * p; // DWORD Ÿ��, *:������, p:������ ����	

	// �Ʒ� �ڵ带 �����غ�����.
	// template�� ��� -> "dependent name"
	// => template ���� T�� �����ؼ� ������ �̸�
	// => "T::�̸�" ���� �����Ϸ� ������ "��"���� �ؼ�
	T::data* p1;	// error. p1 ����.
	T::DWORD* p2;	// error. p2 ����.
					// �ٵ� �� �ڵ��� �ǵ��� ������ p2�� ����

	// �ذ�å
	// dependent name�� Ÿ������ ���ǰ� �Ϸ���
	// �����Ϸ����� �˷����..
	typename T::DWORD* p3;	// ok

	
}
int main()
{
	Test t;
	foo(t);
}



