// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort �ϰ� �ʹٸ�
	std::sort(v.begin(), v.end()); 

	// #1. ���Լ� ���� X -  �������� ����

	// #2. ���Լ� �Ϲ��Լ� ��� -> �ζ��� X
	sort(v.begin(), v.end(), cmp));

	// #3. ���Լ� �Լ���ü ��� -> �ζ��� ����
	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>{});

	// #4. Cpp 11 ���ʹ� ���� ǥ���� ��� ����
	// [] : ���� ǥ���� ���� ��ȣ : lambda introducer
	//		"�͸��� �Լ�" ��� �Ѵ�. 	
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });

}





