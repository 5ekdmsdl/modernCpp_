#include <iostream>


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	// � �Լ� ��������� "�Լ� ����"�� ���� �Ǵ�
	foo(3);		// 1. �����Ϸ��� T ����ϱ�� ����
				// 2, T=int�� ���� -> �Լ� ����
				// 3. �Լ� ������ ���� Ÿ���� "int::type" �̵ǹǷ� �Լ� ��������
			// => �̶� "����" �� �ƴ϶� �ĺ������� ���ܵǰ�
			//    foo(...) �� ����ϰ� �˴ϴ�.

	// Substitution Failure Is Not An Error
	// => ġȯ ���д� ������ �ƴϴ�.
	// => SFINAE
}