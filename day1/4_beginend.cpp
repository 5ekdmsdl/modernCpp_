// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>#
#include <string>
#include <string_view> // C++17!!

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };


	// # 1. C++98 시절에 반복자를 얻는 코드
	// => 아래 처럼 반복자의 타입을 직접 사용하면
	// 단점 1. 코드가 복잡해 보이고
	//      2. 컨테이너 변경시 반복자 타입도 변경되어야 합니다.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// # 2. 반복자 타입을 직접 사용하지 말고, auto 사용하세요
	// => 컨테이너 변경시 좌변을 수정할필요 없습니다.
	// => 단 아래 코드는 v 가 배열이라면 error 입니다.
//	auto p1 = v.begin();
//	auto p2 = v.end();


	// (중요) # 3. 멤버 함수 begin 보다 일반 함수 begin 이 유연성이 좋습니다.
	// => 아래 처럼 사용하면 v 가 배열이어도 문제 없습니다.
	auto p1 = std::begin(v);
	auto p2 = std::end(v);

	// 배열도 std:;size 사용하면 변수 타입 상관없이 사용가능
	// 배열 vector 모두 사용 가능
	auto sz1 = std::size(v);

	/////////////////////////////////////////////////////
	// C20에서 반복자 꺼내기!

	std::vector<int> vv = { 1,2,3,4,5 };

	// 반복자를 꺼내는 3가지 방법
	// # 1. 멤버 함수 begin 사용(C++98)
	auto p1 = vv.begin();

	// # 2. 일반 함수 begin 사용(C++11)
	// => v 가 배열이라도 ok
	auto p2 = std::begin(vv);

	// # 3. std::ranges::begin 사용(C++20)
	auto p3 = std::ranges::begin(vv);

	// std::ranges::begin : 안정성이 개선됨,
	auto p4 = std::begin(std::vector<int>{1, 2, 3});
	// std::begin은 임시객체라도 begin이 나온다. => 사용하면 runtime error
	// 근데 빌드는 된다.

	// 그래서 얘는 컴파일 에러 내준다. (좋네)
	auto p4 = std::ranges::begin(std::vector<int>{1, 2, 3});

	///////////////////////////////////////////////////////////////

	// std::string      : 자원(문자열을 소유) 합니다
	// std::string_view : 자원을 소유하지 않고, 빌려서 사용합니다. (C17 부터)
	std::string s = "to be or not to be";
	std::string_view sv = s;
	// sv는 파괴되도 s 멀쩡


	// 아래 코드를 생각해 보세요
	auto p1 = std::ranges::begin(std::vector<int>{1, 2, 3});
	// vector는 자원을 소유한 컨테이너 -> 자원소유하는 컨테이너의 임시객체 전달하면 error
	auto p2 = std::ranges::begin(std::string_view{ s });
	// 근데 빌려쓰는 컨테이너는 임시객체여도 error X
	// 반복자는 결국 자원의 소유자를 가르킨다.

	// C20 : 자원 소유 컨테이너 vs 빌려쓰는 컨테이너 중요하게 된다.
	//         자원을 빌려서 사용하는 컨테이너 인지가 중요하게 됩니다.
	//		   "borrowed range" 용어가 공식적으로 등장하게 됩니다.

	// int& : 가리킬수만 있습니다.(내부 원리는 포인터)
	// borrowed container : 내부 원리 ( 포인터 + 갯수 입니다.)
	//						=> RUST 등에서는 "FAT POINTER" 라고도 합니다.
}