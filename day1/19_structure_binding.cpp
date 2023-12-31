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

	// 모든 멤버를 꺼내고 싶다.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// cpp17 부터 가능 => "Stucture Binding"
	// auto 만 가능 (type 다 알더라도)
	// 갯수도 맞아야한다
	auto [a1, a2, a3] = p3d;

	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	// 실제로 insert하는 과정
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

	//===========================
	// map의 모든 요소 열거 - Cpp14
	for (auto& p : m) {
		// ...
	}

	// Cpp17
	for (auto& [key, value] : m) {
		// ...
	}
}

