#include <iostream>

// nullptr �� ��ü!!
// => ���� ����� ���ô�.
// 1. boost���� ��¥ ������ ��.
// 2. C11 ǥ�ؿ��� ä�õ�.
// => �ٵ� ǥ�ؿ����� nullptr�� Ű����� ��ü�� �ƴ�.

void foo(int* p) {}
void goo(char* p) {}

// ===============================================================
struct mynullptr_t
{
	// ��ȯ ������ : ��ü�� �ٸ� Ÿ������ �Ͻ������� ��ȯ�Ҷ� ȣ��
	//operator int* () { return 0; }
	//operator char*() { return 0; }

	template<typename T>
	inline operator T* () const { return 0; }
};
mynullptr_t mynullptr;
// ================================================================

int main()
{
	foo(mynullptr);
	goo(mynullptr);

	// # nullptr�� literal & type
	// literal : nullptr ���α׷����� ����ϴ� ��
	// type : std::nullptr_t 
	std::nullptr_t p = nullptr;
	foo(p);
}