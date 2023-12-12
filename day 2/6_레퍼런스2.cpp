#include <iostream>

// 90 page
// ���� �̸��� �Լ� 3���� ���� overload ����
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// lvalue -> (1), (2) ȣ�� ����
				// �ٵ�, n != const -> (1) ȣ��,
				// (1) ������ (2) ȣ��

	foo(10);	// rvalue -> (2), (3) ȣ�� ����
				// (3) ȣ��
				// (3) ������ (2)
	
	// **�߿�**
	// lvalue, rvalue �ٸ��� �����Ϸ��� : (1), (3)ó�� �ΰ� �����
	// lvalue, rvalue �Ѱ��� �Լ��� ó�� : (2)ó�� �����
	
	int& r1 = n;
	foo(r1);	// (1), ������ (2)


	int&& r2 = 10; 
	foo(r2);	// (1) ȣ�� ((3) �ƴϰ�!)

	// Ÿ�԰� value category�� �򰥸��� ������.
	//				Ÿ��		value �Ӽ�
	//	n			int			lval		
	//	10			int			rval
	//	pt			Point		lval
	//	Point(1,2)	Point		rval
	//	r1			int&		lval
	//	r2			int&&		rval (�̸��� ���ݾ�!)
	//							(10�� rval������ r2�� lval)
	// ---------------------------------------------------
	// Ÿ���� �ƴ϶� value �Ӽ��� ���� ȣ�� �Լ� �������� ��!

	Point&& r = Point(1, 1);
	// Point(1,1)�� rvalue, ��, ��ȣ�� ���ʿ� �� �� X
	// but, r�̶�� �ڵ�� lvalue, ��ȣ�� ���ʿ� �� ��

	r.x = 10;

	//#2. �Լ� ������ �ǹ̸� ��Ȯ�ϰ� �����ϼ���.
	// f1(int&) : int& Ÿ�� �ްڴ�. (X)
	//				=> lvalue �ްڴ�.
	// f1(int&&) : int&& Ÿ���� �ްڴ� (X)
	//				=> rvalue �ްڴ�.
	
	// #3. 
	int&& r3 = 10;
	foo(r3);						// (1) callback. 
									// r3 Ÿ��:int&&, r3 �Ӽ�:lvalue
	foo(static_cast<int&&>(r3));	// (3) callback
			// => r3�� Ÿ���� int&& �ε� ???
			// => �ٽ� int&& �� ĳ����???
			// => �ᱹ ���� Ÿ�� �ƴѰ��� ?? �̰� � �ǹ̰� ������ ??

	// static_cast<Type>(r3) ���� Type �� && �� �پ� �ִ� ���
	// => "Ÿ�� ĳ����" �� �ƴ� "value �Ӽ��� �����ϴ� ĳ����" �Դϴ�.
	// => cppreference.com ���� "static_cast" ã�� ������
}

// ǥ���� : �ϳ��� ������ ���Ǵ� �ڵ� ����
// 1 ǥ���� -> Ÿ�� + value �Ӽ� (category)
// �ڵ��� ������ ����� ���� �� -> rvalue







