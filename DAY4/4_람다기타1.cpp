// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// ���� ǥ���Ŀ� ��� ����Ÿ �����ϰ� �ʹ�
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

