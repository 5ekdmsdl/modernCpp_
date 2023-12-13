#include <iostream>
#include <vector>
#include <string>

// #1. move 계열에서는 멤버를 std::move로 옮겨라!

template <typename T>
class Object
{
	std::string name;
	int age;
	T data;
public:
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj) : name(obj.name) 
		{ std::cout << "copy" << std::endl; }

	// 1. 예외가 없음을 알리기 위한 noexcept
	// f() noexcept			: 예외 없다.
	// f() noexcept(true)	: 예외 없다.
	// f() noexcept(false)  : 예외가 있을수 있다.

	// 2. 예외가 있는지 조사하기 위한 noexcept
	// bool b = noexcept(exp)

	// noexcept(exp) : exp에 예외가 있는지 알려준다. true / false
	// 예외있는지 true/false 받기 -> 값에 따라 noexcept 활성화/비활성화
	Object(Object&& obj) noexcept( noexcept(data(std::move(obj.data)) )
		//: name(obj.name)			// 나쁜코드 : string의 복사 생성자 사용
		: name(std::move(obj.name)),	// 조은코드 : string move 생성자 호출
		age(obj.age),// 여기에 들어오는 move 생성자들은 모두 noexception 이어야!
		data(std::move(obj.data)) // T에 대해 예외 보장 X -> noexcept로 조사
		// 참고로 noexcept도 다 컴파일러가 해준다..!~!~!~
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{

}

