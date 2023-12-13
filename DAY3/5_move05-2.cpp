#include <string>
#include <iostream>

int main()
{
	// std::move : ���� rvalue �� ĳ���� �� ���Դϴ�.
	//			   �̵������ڰ� �ִ� Ÿ�Ը� ȿ���� �ֽ��ϴ�

	// #1
	std::string s1 = "aaaaaa";
	std::string s2 = std::move(s1);
		// string�� move ������ ����
		// => �ڿ� �̵�

	// #2.
	int n1 = 10;
	int n2 = std::move(n1);		// n1 = 0 ??
				// => �ƴϰ� �׳� rvalue casting�̴�.
	
	// #3.
	int* p1 = new int;
	int* p2 = std::move(p1); // �� �ڵ��
	//int* p2 = p1;			 // �� �ڵ�� ����

	// #4. swap�� ���ؼ�
	std::string s3 = "aaa";
	std::string s4 = "ccc";

	std::swap(s3, s4);	// Cpp98 ������ swap
						// ���� ��ü ���� -> ������.
				// Cpp11 ���� : move �����ڸ� �̿��� swap
				// �Ʒ� ����Լ� swap�̶� �Ȱ���.

	s3.swap(s4);	// s3�� ���� �ּҿ� s4�� ���� �ּҸ� swap = pointer swap







}