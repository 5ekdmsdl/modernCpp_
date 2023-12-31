#include <string>
#include <string_view>

// 함수 인자로 읽기 전용 문자열을 받을때

// #1. call by value - worst.. 절대 사용하지 마세요
void f1(std::string s)
{
}

// #2. call by const reference - 가장 널리 사용. 그러나, C++17 이후는 최선이 아님!!!
// 메모리 오버헤드 : 포인터 주소 끗!
// string class 통해서 문자열 접근
void f2(const std::string& s)
{
}

// #3. std::string_view 를 call by value 로 => best.. 
// C++17 이후라면 이렇게 하세요
// 메모리 오버헤드 : 포인터 주소, 길이
// 문자열 바로 접근 가능
void f3(std::string_view sv)
{
}


int main()
{
	// 이런 경우는 두 경우 모두 괜찮
	std::string s = "to be or not to be";
	f2(s);
	f3(s);

	// 그러나 이경우는 다름...
	// f2 : string 임시객체 생성... 후, string&이 가르킴.! (끔찍)
	f2("to be or not to be");
				// => 인자가 std::string& 이므로 이 문자열을 가지고
				// => heap에 std::string 의 임시객체 생성 - 이 순간의 오버헤드가 큽니다.(문자열자체도 힙에 복사)
				// => 임시객체를 함수로 전달!!!

	// f3 : 상수 메모리에 있는거 가르키기. (휴우)
	// 엄청난 성능 차이!!!!! (왜냐면 컴파일 타임에 이루어지니까)
	f3("to be or not to be");
				// => sv 자체가 상수 메모리에 놓인 문자열을 직접 가리키게됨.
				// => 오버헤드가 거의 없음.
}
