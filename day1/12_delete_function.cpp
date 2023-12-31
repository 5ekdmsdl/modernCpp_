// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// [컴파일러 자동 생성 목록] (사용자가 하나도 안만들면...)
	// = ** Special Member Function **
	// 생성자, 소멸자, 복사생성자, 대입연산자
	// 이동생성자, 이동대입연산자 

	// Cpp11 : 근데 필요없으면 delete 하자.
	Point(const Point&) = delete;
	// cpp98 : 그때그시절... 해결방법, private + 선언만!
private:
	Point(const Point&);
	
};

int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 컴파일러가 만들어주는 복사생성자사용
}