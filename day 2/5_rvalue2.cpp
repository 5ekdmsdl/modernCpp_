// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       표현식(expression) 에 부여 되는 개념
// expression : 한개의 값으로 결정되는 코드 집합
//				=> 최종 결과값이 등호 왼쪽에 올 수 있는가
// 

int main()
{
	int n = 0;

	n * 2 + 7;	// error
				// n * 2 + 7 최종 결과는 임시 값 -> rvalue

	(n = 10) = 20;	// ok, "n=10" exp = lvalue
	n = 3;
	++n = 10;		// ok. "++n" exp = lvalue

	n++ = 10;		// error, "n++" exp = rvalue

}
// 왜 lval vs rval 구분하려할까?
// lval vs rval일때 다르게 동작하는 함수 구현을 위해!

// foo( lvalue ) : 인자가 호출뒤에도 살아있을 예정
// foo( rvalue ) : 인자가 호출뒤에 안쓰일 예정