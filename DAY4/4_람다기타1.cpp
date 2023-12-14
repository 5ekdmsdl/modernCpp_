// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// 람다 표현식에 멤버 데이타 접근하고 싶다
		//auto f = [](int a) { return a + data; };			// error
		//auto f = [data](int a) { return a + data; };		// error

		auto f = [this](int a) { return a + this->data; };		// error


	}
};

int main()
{
	Test t;
	t.foo(); 
}

