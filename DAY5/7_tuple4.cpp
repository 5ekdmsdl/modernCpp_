// Step3. ������ �����ϱ�

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
// ���� t3�� int�� �����ϰ� ������,
// ��� Ŭ�������� �׿��� type���� ������.

int main()
{
	tuple<> t0;
	tuple<             short> t1; // t1 �� short ����
	tuple<     double, short> t2; // t2 �� double ����
	tuple<int, double, short> t3; // t3 �� int �� ����
}