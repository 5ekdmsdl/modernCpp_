class Meter {
public:
	int value;

	Meter(int sz) : value(sz) {};

	Meter operator-() { return Meter(-value); }
};

// #�ٽ� 1 : ���� Ÿ���� ǥ�ؿ� ���� �����Ǿ�����
// ��������Ҷ����� unsigned long long

// 2. ǥ����ȸ» : �ǵ��� �Ϲ� �����ڴ� ���ο� ���̻� ������ ����
// ���� ����� ������ _ ������ ������

Meter operator""_m(unsigned long long sz) {
	return Meter(sz);
}

int main()
{
	double d = 3.4;
	float f = 3.4f;		// f ���̻� : 3.4 Ÿ���� float�� ������.

	//cpp11 ���� ���̻� ����� ���� ����
	Meter a = 30_m;	// operator""m(30) ȣ��
	//Gram b = 30g;

	-30_m;			// 30_m -> Meter ��ü ���� -> Meter operator- ȣ��
	
	return 0;
}




