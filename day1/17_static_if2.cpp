// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	// # case 1 : �׳� if
	// �Ʒ��� ������ error, 
	// �ֳĸ�... 
	// if : ���� �ð� ���
	// ���ǹ��� ������ �ð��� false�̴��� �ν��Ͻ�ȭ�� �Լ��� ���Եȴ�.

	/*if (false)
		*a = 10;*/

		// # case 2 : "static if" == "if constexpr"
		//  if constexpr :  ������ �ð� ���
		//                 ���ǹ��� ������ �ð��� false �� �����Ǹ�
		//				   �ν��Ͻ�ȭ�� �Լ����� ���� �ȵ�.
		//				   C++17

	if constexpr (false)
		*a = 10;
}
int main()
{
	foo(0);
}

