#include <unordered_set>

typedef std::unordered_set<int> USET_INT;
typedef std::unordered_set<double> USET_DOUBLE;

// - typedef로 템플릿 별명 짓기
// 위처럼 타입 별명 만들지 말고, 아래 처럼 템플자체의 별명 가능할까?
// 타입 없으면 템플릿임! 
// 근데 typedef는 C언어 출신이라, 템플릿 지원 X
//typedef std::unordered_set USET;

// - 대신 using으로 별명 짓자.
// using은 타입, template을 별명 짓기 가능..!
// using이 typedef 완벽히 대체 가능

// #1. type 별명
using DWORD = int;

// #2. template 별명
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
