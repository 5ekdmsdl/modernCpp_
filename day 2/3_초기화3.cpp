int main()
{
	// Cpp98���� �ʱ�ȭ ����
	int  n1 = 3.4;	// ok, but ������ �ս�
					// C / C++ ����������, �ٸ� ��� error
	char c1 = 500;  // ����, but overflower

	// prevent narrow - 56 page �߰��κ�
	int n2{ 3.4 };  // error
	char c2{ 500 }; // error
	// ����....�� �̰Ŵ� ä��!!!!
}