// 8_nullptr2
#include <iostream>

void foo(int* p) {}

// ���ڷ� "�Լ�"�� "����"�� �޾Ƽ�
// => "�Լ�(����)" ���·� ȣ���ϴ� �Լ�
template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}

int main()
{
	foo(0); // ok
	//forward_parameter(foo, 0); 
	// foo(0)�� �ƴ϶� foo(int(0)) �� �� -> error
	// template���� type deduction ��ġ�鼭 type �ٲ�
	// => �׷��� nullptr ����!

	forward_parameter(foo, nullptr); // ���....


}








