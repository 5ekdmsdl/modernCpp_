#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

// std::move ���� �����
template<typename T>
T&& mymove(T&& obj) {
	// �Ʒ� �ڵ�� rvalue casting X
	//		rvalue -> rvalue,
	// but, lvalue -> lvalue
	return static_cast<T&&>(obj);
		// = forward<T>(obj);

	// �ذ�å
	// move�� �׻� rvalue�� ĳ���� �Ǿ���Ѵ�.
	// T�ȿ� ��� ���� ���� -> && �ٿ��� ĳ����
	
	return static_cast<std::remove_reference_t<T> &&> (obj);
			// �� �ڵ�� �׻� rvalue ĳ����
}

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o1);
	Object o4 = mymove(o2);		// ����� ���ô�.
	Object o4 = mymove(Object());		// ����� ���ô�.
}