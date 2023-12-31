// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열에서 \ : 특수 문자 표시용 문자로 취급
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw string에서 \ : \를 일반 문자로 취급
	std::string s2 = R"(\\.\pipe\server)";

	// R : raw string 표시
	// "( : 시작,      )" 끝
	// 
	// => 문자열 안에서 )"는 적을 수 없음 ㅠㅠ
	
	// => 갠찬갠찬 문자열 시작, 종료 바꿀 수 있음!
	// "{아무거나}( 
	std::string s3 = R"12(\\.\pipe\server)12";
}