#include <iostream>9
#include <type_traits>

// (__VA_ARGS__) �� ��ȣ�� ��Ģ 2�� �����Ű�� ���� ��
#define VALUE_CATEGORY(...) \
	if (std::is_lvalue_reference_v<decltype( (__VA_ARGS__) )>) \
		std::cout << "lvalue" << std::endl; \
	else \
		std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;
	
	VALUE_CATEGORY(n);			// lval
	VALUE_CATEGORY(n + 1);		// rval
	VALUE_CATEGORY(n = 10);		// lval
	VALUE_CATEGORY(++n);		// lval
	VALUE_CATEGORY(n--);		// rval
	VALUE_CATEGORY(10);			// rval

	VALUE_CATEGORY("hello");	// lval 
	// ����, �Ǽ� ���ͷ� -> rval
	// ���ڿ� ���ͷ� -> lval

	"hello"[0] = "d";	// const�� error  �ΰ�@



}