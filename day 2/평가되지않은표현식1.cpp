// �򰡵�������ǥ����1.cpp

#include <typeinfo>
int add(int a, int b) { return a + b; }

int main()
{
	// #1. expression(ǥ����) : �Ѱ��� ������ �����Ǵ� �ڵ� ����
	int n = 10;
	
	n * 2 + 3;
	add(1, 2);

	// #2. decltype() �� () �ȿ��� expression �� ����� �մϴ�.
//	decltype(int) d;  // error. int ��� Ÿ���� �ƴ� expression �� �־�� �մϴ�.


	// #3. decltype(exp) : exp �� �����ϴ� ����  Ÿ���� �����ϴ� ��
	decltype( add(1, 2) ) ret = add(1, 2);
	// ������ exp : ��¥ ȣ��
	// ���� exp : �����Ϸ����� �˷��ִ� �͸� => unevaluated expression
	// => �򰡵��� �ʴ� ǥ����

	// ## Cpp�� �򰡵��� �ʴ� ǥ���� ���� 4����
	// decltype, sizeof, noexcept, typeid
	decltype(add(1, 2)) d;
	int n = sizeof(add(1, 2));
	bool b = noexcept(add(1, 2));
	const std::type_info& t = typeid(add(1, 2));

	// ================================================
	// �캯�� Ÿ���� auto�� �ƴ� decltype ��Ģ���� �����ش޶�.
	// = auto �ڸ��� �캯�� ǥ������ �־�޶�.
	decltype(auto) ret = add(1, 2);
}
