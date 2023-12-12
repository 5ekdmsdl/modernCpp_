#include <iostream>9
#include <type_traits>

// (__VA_ARGS__) 의 괄호는 규칙 2를 적용시키기 위한 것
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
	// 정수, 실수 리터럴 -> rval
	// 문자열 리터럴 -> lval

	"hello"[0] = "d";	// const라서 error  인것@



}