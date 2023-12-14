#include <iostream>
#include <vector>
#include <string>

// #1. move �迭������ ����� std::move�� �Űܶ�!

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

	// 1. ���ܰ� ������ �˸��� ���� noexcept
	// f() noexcept			: ���� ����.
	// f() noexcept(true)	: ���� ����.
	// f() noexcept(false)  : ���ܰ� ������ �ִ�.

	// 2. ���ܰ� �ִ��� �����ϱ� ���� noexcept
	// bool b = noexcept(exp)

	// noexcept(exp) : exp�� ���ܰ� �ִ��� �˷��ش�. true / false
	// �����ִ��� true/false �ޱ� -> ���� ���� noexcept Ȱ��ȭ/��Ȱ��ȭ
	Object(Object&& obj) noexcept( noexcept(data(std::move(obj.data)) )
		//: name(obj.name)			// �����ڵ� : string�� ���� ������ ���
		: name(std::move(obj.name)),	// �����ڵ� : string move ������ ȣ��
		age(obj.age),// ���⿡ ������ move �����ڵ��� ��� noexception �̾��!
		data(std::move(obj.data)) // T�� ���� ���� ���� X -> noexcept�� ����
		// ������ noexcept�� �� �����Ϸ��� ���ش�..!~!~!~
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{

}
