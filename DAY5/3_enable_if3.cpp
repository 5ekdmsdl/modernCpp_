#include <iostream>
#include <type_traits>

// enable_if ��� ����
// std::enable_if<����, Ÿ��>::type�� ���� ���
//					���� == true  : "Ÿ��" 
//					���� == false : "::type" ��� error

// �Ʒ� ���� Ÿ���� �ڵ尡 �ٽ��Դϴ�.
template<typename T>

// T�� �����ؼ� type ������ typename �� ����ؾ�
typename std::enable_if< std::is_integral_v<T>, T>::type;
			// T�� �������, ���� ���(����Ÿ��) : T
			// T ���� �ƴ϶��, "::type" ����. �Լ� ���� ����
			// SFINAE ��Ģ ���� -> ���� �ĺ����� ����


// T�� �����ؼ� type ������ typename �� ����ؾ�		
//typename std::enable_if< std::is_integral_v<T>, T>::type;
// �Ǵ� �Ʒ� ó�� ǥ��
template<typename T>
std::enable_if_t<std::is_integral_v<T>, T>;


gcd(T a, T b)
{
	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);			// T ���� ���
	gcd(3.1, 5.4);		// exactly matching -> double ���� ���
	gcd(3.1f, 5.4f);	// �Լ� ���� ���� ->T ������ �ĺ����� ���� 
						// -> double ���� ���
}