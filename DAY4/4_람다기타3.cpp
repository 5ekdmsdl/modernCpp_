int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	// int�� double swap �ϴ� �ڵ� -> ����! �����Ѵ�...
	swap(n, d);
			// "generic lambda"�� ���ڰ� Ÿ���� ���� �ٸ��� �ϴϱ� ����X

	// �ذ�å : 1, 2���� ���ڰ� ���ƾ� �Ѵ�!
	// =>Cpp 20���� "template lambda" ���� �߰�
	auto swap2 = []<typename T>(T& a, T& b) { };
	swap2(n, d);	// template ����� ���� -> compile error


}