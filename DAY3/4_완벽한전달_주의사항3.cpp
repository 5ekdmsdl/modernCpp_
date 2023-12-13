// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 이거는 "forward ref" X
	// 왜냐면 함수 자체가 template 이여야 forward ref
	// => foo는 클래스 템플릿 (Test)의 일반 멤버 함수 
	void foo(T&& arg)
	{
	}

	// 이거는 "forward ref" 맞음
	template<typename U>
	void goo(U&& arg) {

	}
};
int main()
{
	int n = 0;
	Test<int> t;	// 여기에서 T=int로 결정되어서 
					// void foo(int&& arg) 이미 생성됨
					// => foo는 함수 템플릿 X

	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);		// ok
	t.foo(10);		// error

	t.goo(n);		// ok
	t.goo(10);		// ok
}