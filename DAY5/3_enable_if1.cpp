// 6_enable_if1.cpp
// �Ʒ� �ڵ� (enable_if) �̹� Cpp11 ǥ�ؿ� ����.

template<bool, typename T = void > struct enable_if
{
	using type = T;
};
// type �� ������ default void

template<typename T> struct enable_if<false, T> 
{
	// �ٽ� : type ����� ����!
};

// enable if ���� : enable_if<bool ��, Ÿ��>
// �ٽ� : 1��° ���� false -> �κ� Ư��ȭ ���� ����

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1;		// int n1
	enable_if<true>::type       n2;		// void n2
	enable_if<false, int>::type n3;		// (::type ���) error

	// enable_if �� ����� ��
	// 1. enable_if<false, Ÿ��>::type�� ����, type�� ����.
	// 2. enable_if<true,  Ÿ��>::type -> "Ÿ��"
	// 3. enable_if<true>::type		   -> "void"
	//



}


