// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// �Ϲ� ���ڿ����� \ : Ư�� ���� ǥ�ÿ� ���ڷ� ���
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw string���� \ : \�� �Ϲ� ���ڷ� ���
	std::string s2 = R"(\\.\pipe\server)";

	// R : raw string ǥ��
	// "( : ����,      )" ��
	// 
	// => ���ڿ� �ȿ��� )"�� ���� �� ���� �Ф�
	
	// => �������� ���ڿ� ����, ���� �ٲ� �� ����!
	// "{�ƹ��ų�}( 
	std::string s3 = R"12(\\.\pipe\server)12";
}