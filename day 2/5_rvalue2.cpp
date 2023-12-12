// �ٽ� : rvalue, lvalue �� ������ 
//       ����(��ü)�� �ο��Ǵ� ������ �ƴ�
//       ǥ����(expression) �� �ο� �Ǵ� ����
// expression : �Ѱ��� ������ �����Ǵ� �ڵ� ����
//				=> ���� ������� ��ȣ ���ʿ� �� �� �ִ°�
// 

int main()
{
	int n = 0;

	n * 2 + 7;	// error
				// n * 2 + 7 ���� ����� �ӽ� �� -> rvalue

	(n = 10) = 20;	// ok, "n=10" exp = lvalue
	n = 3;
	++n = 10;		// ok. "++n" exp = lvalue

	n++ = 10;		// error, "n++" exp = rvalue

}
// �� lval vs rval �����Ϸ��ұ�?
// lval vs rval�϶� �ٸ��� �����ϴ� �Լ� ������ ����!

// foo( lvalue ) : ���ڰ� ȣ��ڿ��� ������� ����
// foo( rvalue ) : ���ڰ� ȣ��ڿ� �Ⱦ��� ����