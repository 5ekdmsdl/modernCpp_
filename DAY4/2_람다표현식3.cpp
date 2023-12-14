#include <iostream>

// auto �� ���� ǥ����

int main()
{
//	int foo() {} // �Լ� �ȿ� �Լ�, local function, nested function �̶�� �մϴ�

	// #1. ����ǥ������ auto ������ ��Ƽ� �Լ� ó�� ��밡���մϴ�.
	// => �Ϻ� ���(C#��)�� �Լ� �ȿ� �Լ��� ����� �ֽ��ϴ�.
	// => C++ �� �Լ� �ȿ� �Լ��� ����� ���µ�
	//    �Ʒ� ó�� ����� �ᱹ, local function �� ����Ͱ� �����մϴ�.

	auto add = [](int a, int b) { return a + b; };
				// class ClosureType{ operator()(){} }; ClosureType();

	int n1 = add(1, 2);
	int n2 = add.operator()(1, 2);	// ok.. �ᱹ �Լ� ��ü�̹Ƿ� 
									// �̷��� ����ص� �˴ϴ�


	// #2. ������ ������ ��� ������ - f2 �Ѱ� ����
	// 
	//     ������ �ƴ� �ڵ��� �ּ��� �ڵ带 ������ - f1 �� �ּ�!!!
	// 
	// �ٽ� : ����ǥ������ ���� ����� "�ӽð�ü(rvalue)" �̴�.

	auto  f1       = [](int a, int b) { return a + b; }; // ok
	auto& f2       = [](int a, int b) { return a + b; }; // error.
								// => �ӽð�ü�� lvalue reference �� ����ų�� ����

	const auto& f3 = [](int a, int b) { return a + b; }; // ok	
			// �ӽ� ��ü�� const ref �� ���� �� �ִ�!
	auto&& f4      = [](int a, int b) { return a + b; }; // ok
					// auto&& �� "forwarding reference" �ε�.
					// �캯�� rvalue �̹Ƿ� auto : �� Ÿ��, auto&& ��  Ÿ��&&(rvalue reference)


	// �ּ��� �ڵ� �ٰ�
	//auto f1 = [](int a, int b) {return a + b; };
	//auto f1 = ClosureType();		// ������ 1ȸ ȣ��, �߰� ������� X
	//
	//auto&& f2 = [](int a, int b) { return a + b; };	// �ӽ� ��ü �����, �ּ� ��� �ֱ�
	//ClosureType* f2 = &ClosureType();	// �ּҸ� ���󰡼� ���
										// ���� ���� X -> �ణ�� ������� �߻�!

}

// ���� : Point pt = Point(1, 2) �� ���ؼ� ������ ���ô�.

// Cpp 98
// Point pt = Point(1,2)
//			1. �ӽ� ��ü ����,
//			2. �ӽ� ��ü�� pt�� ���� (���� ������)
//			=> �ٵ�, ��κ��� �����Ϸδ� �ӽ� ��ü ����, ���� ���� ȣ�� ����
//			=> ��� ���� 2���� ������ ȣ�� 
//				(copy ellision, elide copy constructor) 
//			
//			=> (!!)�׷���, Point�� ���� �����ڸ� private �� ������ ����
// 
// Cpp 11
// Point pt = Point(1,2)
//			1. �ӽ� ��ü ����
//			2. �ӽ� ��ü pt�� �̵� (�̵� ������)
//			=> �׷���, ���� ��κ� �����Ϸ��� ����ȭ -> ���� 2�� ������ ȣ��
// 
// Cpp 17
// Point pt = Point(1,2)
//			1. ���� 2�� ������ ȣ��
//			=> �ӽ� ��ü ����, ���� �����ϴ� ���� ����ȭ ��.
//			=> ���� �����ڿ� �̵� ������ ��� private�� �־ ���� X
//			=> ������尡 ���� X
// 






