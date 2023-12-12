// member field initialization

//class Point
//{
//	// Cpp11에서 멤버 데이터 초기값 넣을 수
//	int x = 0;
//	int y = 0;
//public:
//	Point() {}
//	Point(int a) : y(a) {}
//};

// => 컴파일러 보정의 결과물
class Point
{
	int x; // = 0;
	int y; // = 0;
public:
	// 멤버 초기값 보고, 컴파일러가 생성자 바꿈.
	Point()		 : x(0), y(0) {}
	Point(int a) : x(0), y(a) {}
	// 이미 초기화값이 있으면 아닌 것만 추가
};