int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	// int와 double swap 하는 코드 -> 에러! 여야한다...
	swap(n, d);
			// "generic lambda"는 인자가 타입이 각각 다르게 하니까 에러X

	// 해결책 : 1, 2번쨰 인자가 같아야 한다!
	// =>Cpp 20부터 "template lambda" 문법 추가
	auto swap2 = []<typename T>(T& a, T& b) { };
	swap2(n, d);	// template 만들기 실패 -> compile error


}