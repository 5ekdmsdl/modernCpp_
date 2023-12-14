// QA
// nasm 을 학습하는게 좋습니다.
// 1. windows 와 linux, osx 모두 가능
// 2. intel 어셈과 거의 동일, godbolt.org 문법과 거의 동일
// 3. 문법 쉽고, 자료 많습니다.
// 4. "nasm tutorial"

// 함수와 클래스(구조체)
// # 함수 : 기계어
void foo()
{
	// ...
}

// # 클래스 :	컴파일러가 이해하는 타입 
//				멤버함수들은 기계어로 저장 -> assembly에는 class 정의 부분이 X
class Point
{
	int x;
	int y;
public:
	void set(int a, int b)
	{
	}
};

int main()
{
	Point pt;			// 스택에 8바이트 할당하는 기계어
						// sub rbp, 8

	pt.x = 10;			// pt 주소 윗부분의 메모리 = 10
	pt.set(10, 20);		// call Point::set(&pt, 10, 20)
}







