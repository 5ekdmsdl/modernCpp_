#include <iostream>
#include <type_traits> // �� ����� ���� traits �� �̹� ������� �ֽ��ϴ�.
// C++11 ���� �����Ǵ� ���

// cppreference.com ���� 1��° ȭ�鿡�� type_tratis ������ ������


template<typename T> void printv(const T& v)
{
	// if : ���� �ð� ���ǹ�, ������ �ð��� ���� false����
	//		���ø� -> ���� �Լ����鶧�� ���Ե�.
	//		����, ���ุ �ȵǴ°�
	// => �ذ�å
	// => ������ �ð��� �Լ��� ��������. -> ������ �ð� ���ǹ�
	// 
	// if constexpr : ������ ���ǹ�, ������ �ð��� ���� false��,
	//				  ���ø� -> ���� �Լ� ���� X
	//				  ��, Cpp 17 ���� ����
	
	//if (std::is_pointer<T>::value)
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;

	//else if constexpr (std:: ... )

	else
		std::cout << v << std::endl;

	// => �ƹ��� ���ǹ� ���Ƶ� �����پ������� �ٽɸ� ������!
	// => ���̺귯�� ���鶧 ¯!
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

