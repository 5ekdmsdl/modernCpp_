// constexpr function
// 1. 인자 값을 컴파일 시간에 알 수 있고,
// 2. 컴파일 시간에 값을 알아야하는 위치라면
// => 함수 실행을 컴파일할때 수행하라!!

constexpr int Factorial(int n)
{
	// 단 메모리 할당 등 런타임이 필요한 동작들은 X
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)];		// ok 컴파일 하면 int arr1[120]

	int arr2[Factorial(n)];		// error, 컴파일 타임에 알 수 X


	int s = Factorial(5);		// ok, 실행 시간에 수행

	int s2 = Factorial(n);		// 컴파일 시간 vs 실행 시간 
								// -> 컴파일러마다 다를 수 (표준 정의 X)

	const int s3 = Factorial(5);		// 애도 컴파일러 마다 다를 수,,,
	
	constexpr int s4 = Factorial(5);	// 컴파일 시간! constexpr이니까



}