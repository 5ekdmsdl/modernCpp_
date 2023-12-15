// Step2. 1개 보관하기

template<typename ... Types>
struct tuple {
	static constexpr int N = 0;		// 보관하는 요소의 갯수
};

// tuple 사용 시 타입이 한개 이상 있는 경우에 대한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>			// 한개 타입 & 나머지 것들 버전의 부분 특수화
{
	T value;

	tuple() = default;
	tuple(const T& arg) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}

