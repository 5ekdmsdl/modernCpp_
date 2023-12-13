// 105 page.. ��� ��ü�� move
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
	Object o2 = std::move(o1);	// move ������ ȣ��
	
	const Object o3;
	Object o4 = std::move(o3);	// copy ��� ��ü�� move X
			// �ֳĸ� move�� �̵� �Ŀ� �ʱ�ȭ������ϴµ�, ���� �Ұ�!
			// static_cast< const Object&& >(o3)
			// const Object -X-> Object&&
			// const Object ---> const Object&, ��Ŵ� ����
			// ������ �ƴϰ�, ���� ������ ȣ��
	
	// �� ����ϼ���!
	//	: ��� ��ü�� move �� �� X
	//  
}



