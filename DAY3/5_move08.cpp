#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 1. 사용자가 복사 계열 함수 와 이동 계열(이동생성자, 이동 대입 연산자)를 모두 제공하지 않으면
// => 컴파일러가 모두 디폴트 버전 제공
// => 컴파일러가 제공한 복사 생성자 : 모든 멤버를 복사
// => 컴파일러가 제공한 이동 생성자 : 모든 멤버를 이동(std::move 사용) 

// 규칙 2. 사용자가 복사 생성자만 제공하면
// -> 컴파일러가 이동생성자 default 생성 X
// => 혹시 이동이 필요한 코드 있으면 "사용자가 만든 복사 생성자" 사용

// => 컴파일러에게 move 계열 함수 요청 하려면 -> = default 사용!

// 규칙 3. 사용자가 이동 생성자만 제공
// -> 컴파일러 복사 생성자 default 생성 X
// 근데 그렇다고 rvalue로 이동은 X => 컴파일 에러

// => 컴파일러에게 복사 = default로 요청 가능!

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}	// 생성자!
	// 핵심 : 사용자가 복사, 이동 생성자를 만들지 않는다!
	//		  컴파일러가 만들어준다!

	// 복사 계열만 만들면
	Object(const Object& obj) : name(obj.name) {
		std::cout << "copy" << std::endl;
	}

};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 모든 멤버 복사로 옮기기
	Object o4 = std::move(o1);	// 모든 멤버 이동으로 옮기기

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}