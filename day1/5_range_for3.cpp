#include <iostream>
#include <vector>

// ����� ���� Ÿ���̶�� 
// begin/end �� ������ range-for �� ������ �ֽ��ϴ�.
// ��!! �Ʒ� ������ ��� ����� ���� Ÿ���϶��� ��� ����
struct Point3D
{
	int x, y, z;

	int* begin() { return &x; }
	// ������ ����� �ּҰ� �ƴ� ������ �ּ��� ���� �ּ�
	int* end() { return &z + 1; } 
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;
	
	for (int n : (p))  // �ɱ�� ? �ǰ��Ϸ��� �ʿ��� ���� ?
		std::cout << n << std::endl;
}















