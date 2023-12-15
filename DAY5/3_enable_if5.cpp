#include <iostream>
#include <type_traits>

//template<typename T> void printv(const T& v)
//{
//	// error : T=int�϶�,
//	// => �ν��Ͻ�ȭ�� �Լ��� "*v"�� ���ԵǼ� ����!
//	if (std::is_pointer_v<T>)
//		std::cout << v << " : " << *v << std::endl;
//	else
//		std::cout << v << std::endl;
//}

//// if constexpr �����ѵ�,,, Cpp17���� ����!
//template<typename T> void printv(const T& v)
//{
//	if constexpr (std::is_pointer_v<T>)
//		std::cout << v << " : " << *v << std::endl;
//	else
//		std::cout << v << std::endl;
//}

// Cpp 17 �������� enable_if�� �ذ� (��� �߿�)
template<typename T> 
std::enable_if_t<std::is_pointer_v<T>>
printv(const T& v) 
{
	std::cout << "������ ����" << std::endl;
	std::cout << *v << std::endl;
}

template<typename T> 
std::enable_if_t<!std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << "������ �ƴ� ����" << std::endl;
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}
// https://github.com/aosp-mirror (�ȵ���̵� �ҽ�)

// platform system core
// libutils/include/utils
