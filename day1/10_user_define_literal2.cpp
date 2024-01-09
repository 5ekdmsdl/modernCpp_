// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 
using namespace std::literals;	// 요 ns 있어야 표준 리터럴 사용가능

void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello");		// const char*
	foo("hello"s);		// string

	std::chrono::seconds s1(10);
	auto s2 = 10s;			// 위에서 사용한 방식과 똑같음 (좀 편할지도)
	
	// 표준에서 제공한 literal만 사용하자~!
	std::chrono::seconds s3 = 1h + 30min + 20s;
}


