// Step2. 1�� �����ϱ�

template<typename ... Types>
struct tuple {
	static constexpr int N = 0;		// �����ϴ� ����� ����
};

// tuple ��� �� Ÿ���� �Ѱ� �̻� �ִ� ��쿡 ���� �κ� Ư��ȭ
template<typename T, typename ... Types>
struct tuple<T, Types...>			// �Ѱ� Ÿ�� & ������ �͵� ������ �κ� Ư��ȭ
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

