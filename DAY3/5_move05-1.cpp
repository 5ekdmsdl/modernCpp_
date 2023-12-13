#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

// std::move 직접 만들기
template<typename T>
T&& mymove(T&& obj) {
	// 아래 코드는 rvalue casting X
	//		rvalue -> rvalue,
	// but, lvalue -> lvalue
	return static_cast<T&&>(obj);
		// = forward<T>(obj);

	// 해결책
	// move는 항상 rvalue로 캐스팅 되어야한다.
	// T안에 모든 참조 제거 -> && 붙여서 캐스팅
	
	return static_cast<std::remove_reference_t<T> &&> (obj);
			// 위 코드는 항상 rvalue 캐스팅
}

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o1);
	Object o4 = mymove(o2);		// 만들어 봅시다.
	Object o4 = mymove(Object());		// 만들어 봅시다.
}