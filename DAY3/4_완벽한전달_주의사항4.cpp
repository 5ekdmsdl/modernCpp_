int main()
{
	int n = 3;

	// ������ ������ ��� ������!
	auto& a1 = n;
	auto& a2 = 3;

	// auto�� T�� ��Ģ ����
	// auto&& == T&&
	// auto&&�� rvalue reference X -> forward reference
	// -> �Ʒ� �ڵ� ��� ���� X
	auto&& a3 = n;	// n:lvalue, auto&&:int&, // -> int& a3
	auto&& a4 = 3;	// 3:rvalue, auto&&:int&& -> int&& a4

}

