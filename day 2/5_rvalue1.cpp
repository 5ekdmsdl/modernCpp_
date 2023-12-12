// 4_rvalue - 87 page
int x = 0;
int  foo() {	return x;}
int& goo() { return x; }

// lval : 등호 왼쪽에 올 수 있는 exp (오른쪽도 가능)
//			이름(id) 있고, 단일 식을 넘어 사용 가능
//			주소 연산자 -> 주소 구할 수 
//			참조 반환 하는 함수
// 
// rval : 등호 오른쪽에만 올 수 있는 exp
//			이름(id) 없고, 단일식에서만 사용 가능
//			주소 연산자 -> error (임시로만 사용)
//			반환 타입이 값
//			-> literal, 임시 객체
//

int main()
{
	int v1 = 10, v2 = 10;
	
	v1 = 20;	// ok, v1은 등호 왼쪽 올수 
	10 = v1;	// error, 10은 X
	v2 = v1;
	
	int* p1 = &v1;	// ok
	int* p2 = &10;	// error

	//============================================
	const int c = 10;	// 이름 존재!, 주소 구할수!, 사용자 할당!
	c = 20;				//error -> "수정 불가능한 lval"
						// but, C에서는 rvalue로 분류


	// 모든 rvalue는 상수이다 (X)
	Point(1, 1).x = 10;
	Point(1, 1).set(10, 20);	// ok, 임시객체라도 멤버함수로 변경은 가능


}









