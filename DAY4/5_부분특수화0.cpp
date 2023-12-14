// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	// "클래스이름::이름" 에서 이름은
	// "값" 일수도, "타입" 일수도 있지
	Test::data  * p; // data 값 -> * : 곱하기
	Test::DWORD * p; // DWORD 타입, *:포인터, p:포인터 변수	

	// 아래 코드를 생각해보세요.
	// template인 경우 -> "dependent name"
	// => template 인자 T에 의존해서 꺼내는 이름
	// => "T::이름" 에서 컴파일러 무조건 "값"으로 해석
	T::data* p1;	// error. p1 없다.
	T::DWORD* p2;	// error. p2 없다.
					// 근데 이 코드의 의도는 포인터 p2의 선언

	// 해결책
	// dependent name이 타입으로 사용되게 하려면
	// 컴파일러에게 알려줘야..
	typename T::DWORD* p3;	// ok

	
}
int main()
{
	Test t;
	foo(t);
}



