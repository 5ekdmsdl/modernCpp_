// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	// move 생성자 호출
	
	const Object o3;
	Object o4 = std::move(o3);	// copy 상수 객체는 move X
			// 왜냐면 move는 이동 후에 초기화해줘야하는데, 수정 불가!
			// static_cast< const Object&& >(o3)
			// const Object -X-> Object&&
			// const Object ---> const Object&, 요거는 가능
			// 에러는 아니고, 복사 생성자 호출
	
	// 꼭 기억하세요!
	//	: 상수 객체는 move 될 수 X
	//  
}



