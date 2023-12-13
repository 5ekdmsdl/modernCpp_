// 9_�Ϻ�������_���ǻ���3

// forwarding reference �̾߱�

template<typename T> class Test
{
public:
	// �̰Ŵ� "forward ref" X
	// �ֳĸ� �Լ� ��ü�� template �̿��� forward ref
	// => foo�� Ŭ���� ���ø� (Test)�� �Ϲ� ��� �Լ� 
	void foo(T&& arg)
	{
	}

	// �̰Ŵ� "forward ref" ����
	template<typename U>
	void goo(U&& arg) {

	}
};
int main()
{
	int n = 0;
	Test<int> t;	// ���⿡�� T=int�� �����Ǿ 
					// void foo(int&& arg) �̹� ������
					// => foo�� �Լ� ���ø� X

	
	// �Ʒ� �ڵ带 �����غ�����. ������ ������� ?
	t.foo(n);		// ok
	t.foo(10);		// error

	t.goo(n);		// ok
	t.goo(10);		// ok
}