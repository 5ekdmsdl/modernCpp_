#include <unordered_set>

typedef std::unordered_set<int> USET_INT;
typedef std::unordered_set<double> USET_DOUBLE;

// - typedef�� ���ø� ���� ����
// ��ó�� Ÿ�� ���� ������ ����, �Ʒ� ó�� ������ü�� ���� �����ұ�?
// Ÿ�� ������ ���ø���! 
// �ٵ� typedef�� C��� ����̶�, ���ø� ���� X
//typedef std::unordered_set USET;

// - ��� using���� ���� ����.
// using�� Ÿ��, template�� ���� ���� ����..!
// using�� typedef �Ϻ��� ��ü ����

// #1. type ����
using DWORD = int;

// #2. template ����
template<typename T>
using USET = std::unordered_set<T>;

int main()
{
	std::unordered_set<int>    s1;
	std::unordered_set<double> s2;

	USET_INT ss1;
	USET_DOUBLE ss2;

	USET<int> sss1;
	USET<double> sss2;
}
