// Step3. 여러개 보관하기

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using baseTypes = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ...args) 
			: value(v), baseTypes(args...) {}

	static constexpr int N = baseTypes::N + 1;
};

//  t<i,d,s> -> t<d, s> -> t<s> -> t< >
// 지금 t3는 int만 보관하고 있지만,
// 기반 클래스들이 그외의 type들을 보관함.

int main()
{
	tuple<> t0;
	tuple<             short> t1; // t1 은 short 보관
	tuple<     double, short> t2; // t2 는 double 보관
	tuple<int, double, short> t3; // t3 는 int 만 보관
}