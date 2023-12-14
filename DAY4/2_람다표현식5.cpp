// 143 
#include <functional>
#include <format>
#include <vector>

int foo(int a, int b) { return 0; }

int main()
{
	// 람다표현식을 담는 방법

	auto f1 = [](int a, int b) { return a + b; };
	int(*f2)(int, int) = [](int a, int b) { return a + b; };// 함수 포인터
				// 우변이 임시 객체인데,.. 어떻게 함수 포인터에 담지?

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	//===============================================================
	// # 특징 1 :auto 변수에 다른 람다 담을 수 X, 근데, f2, f3는 가능
	// f1 : 컴파일러가 만든 클래스 타입 - 모든 람다가 다른 타입.
	// f2 : 함수 포인터 타입
	// f3 : std::function 타입

	//f1 = [](int a, int b) { return a + b; };	// error
	f2 = [](int a, int b) { return a + b; };	// ok
	f3 = [](int a, int b) { return a + b; };	// ok

	//===============================================================
	// # 특징 2.
	f1(1, 2);	// f1.operator()(1,2) 함수 이름 직접 호출
				// => 인라인 치환 가능

	f2(1, 2);	// (*f2)(1,2) 함수의 주소 꺼내서 호출 
				// => inline X (근데 또 나중에 모르기는 함...)
	
	f3(1, 2);	// f2와 유사 -> 치환 X
	// 결론 : 람다 표현식을 inline하면서 변수에 담고 싶다면
	// auto type에 넣자...
	// 근데 교체 가능하게 하고 싶다면 std::function

	//===============================================================
	// # 특징 3. 람다표현식 여러개를 컨테이너(vector)에 보관하고 싶다.
	// => STL 컨테이너는 같은 타입을 여러개 보관합니다.
	// => 람다 표현식은 다른 타입이므로 컨테이너에 보관할수 없지만
	// => std::function 을 보관하는 컨테이너를 만들면 됩니다.

	std::vector<std::function<int(int, int)> >  v;

	v.push_back([](int a, int b) { return a - b; });
	v.push_back([](int a, int b) { return a + b; });
	v.push_back([](int a, int b) { return a * b; });
	v.push_back(foo);
	// 위 v에는 람다 포함 signature 동일한 모든 함수 담을 수 있다.

	// 함수 포인터를 보관하면 안되나요 ?
	// => 가능한데.. std::function 으로 하세요..
	// => 이유는 캡쳐한 람다는 함수 포인터 변환 안됩니다. (오후)
}

