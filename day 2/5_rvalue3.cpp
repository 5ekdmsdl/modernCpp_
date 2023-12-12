#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	n + 5 = 20; // error. "n + 5" �� rvalue

	// lvalue, rvalue �����Ϸ���
	// -> decltype�� ��Ģ�� �����϶�.
	using T = decltype(n + 5);
	// decltype : lvalue -> T : ����
	//			  rvalue -> T : �� Ÿ��
	using T2 = decltype(++n);
	using T3 = decltype(n++);
	using T4 = decltype(n);		// n : lvalue����, 
								// �̸��� �ִ� -> ���� Ÿ��

	if (std::is_lvalue_reference_v<T>)
		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;
}