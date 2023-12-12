// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자 : 직접 초기화만 가능
	// main의 copy init은 모두 error
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// #1. 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);			// Cpp98, direct init
	Vector v2 = 10;			// Cpp98, copy init
	Vector v3{ 10 };		// Cpp11, direct init + uniform
	Vector v4 = { 10 };		// Cpp11, copy init + uniform

	//----------------
	// #2. 
	foo(10); // 함수 인자 전달 copy init
			 // Vector v = 10
				// 복사 초기화는 위험 -> explicit 사용하자.
}







