// �Լ� ���ڷ�
// int&  : int Ÿ���� lvalue �� ������ �ִ�.
// int&& : int Ÿ���� rvalue �� ������ �ִ�.
// T&    : ��� Ÿ���� lvalue �� ������ �ִ�.

// T&&   : ��� Ÿ���� lvalue & rvalue ���� �� �ִ�.
// ��� �޴´�, = ������ ��츦 ���� �� �ִ� �Լ� �����Ѵ�,

// �Ʒ� ���� �ܿ켼��
// ���� lvalue ���� f4(n) : 
//			T:int&, ����:T&&=int& &&, �����Լ�:f4(int&)
// ���� rvalue ���� f4(3) : 
//			T:int, ����:T&&=int&&, �����Լ�:f4(int&&)

// => �� ��� ���ڸ� ���纻 ���� ���� �� �ִ� �Լ� ����

// ��� ����
// int&		: lvalue reference
// int&&	: rvalue reference
// T&		: lvalue reference

// T&&		: rvalue reference�� �ƴϰ�,
//				lvalue & rvalue ��� ���� �� �ִ�.
//				=> "universal reference" = "forwarding ref"




