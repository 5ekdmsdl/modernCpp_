// 각 요소들 int 사용
//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

// 여기서는 char 사용하도록 명시 가능
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main() {
	auto day = DAYOFWEEK::MON;
}




