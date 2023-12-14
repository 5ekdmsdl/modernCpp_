// 5_����ǥ����5
#include <iostream>
#include <vector>
#include <algorithm>

// ����ǥ���İ� Ÿ��

int main()
{
	// #1. ��� ���� ǥ������ �ٸ� Ÿ��!
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx();
	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy();

	std::cout << typeid(f1).name() << std::endl;

	// #2. ���� ǥ�������� �ʱ�ȭ�� ������, �ٸ� ���� ǥ���� ���� �� x
	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; };		// Ÿ���� �޶� error!

	// #3. 
	std::vector<int> v = { 1,2,3 };
	// �Ʒ� �ڵ�� sort 3�� ������!
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });

	auto cmp = [](int a, int b) { return a < b; };
	// ���⼭�� sort 1�� ������!
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	// ����� ��� inline �ȴ�.

	// �ѹ��� ���Ÿ� �ӽ� ��ü ok, �ٵ� ������ ���ɰŸ� auto ������ ����.

	// ������ ���� <�� �ʿ��ϸ�, "std::less" ����ص� ����.
}





