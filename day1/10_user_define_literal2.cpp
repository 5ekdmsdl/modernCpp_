// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 
using namespace std::literals;	// �� ns �־�� ǥ�� ���ͷ� ��밡��

void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello");		// const char*
	foo("hello"s);		// string

	std::chrono::seconds s1(10);
	auto s2 = 10s;			// ������ ����� ��İ� �Ȱ��� (�� ��������)
	
	// ǥ�ؿ��� ������ literal�� �������~!
	std::chrono::seconds s3 = 1h + 30min + 20s;
}


