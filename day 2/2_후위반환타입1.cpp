// 1_후위반환타입1.cpp - 교재 73 page

// C / C++에서 전통적인 함수 모양
//int square(int a)
//{
//	return a * a;
//}

// C++11 : 함수 반환을 뒤에 표기
// => suffix return type, trailing return type
auto square(int a) -> int
{
	return a * a;
}

int main()
{
	square(3);
}