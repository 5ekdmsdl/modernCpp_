// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// ��� ����� ������ �ʹ�.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// cpp17 ���� ���� => "Stucture Binding"
	// auto �� ���� (type �� �˴���)
	// ������ �¾ƾ��Ѵ�
	auto [a1, a2, a3] = p3d;

	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "������";

	// map�� pair�� �����մϴ�.
	// ������ insert�ϴ� ����
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "ȭ����";
	m.insert(p);

	//===========================
	// map�� ��� ��� ���� - Cpp14
	for (auto& p : m) {
		// ...
	}

	// Cpp17
	for (auto& [key, value] : m) {
		// ...
	}
}

