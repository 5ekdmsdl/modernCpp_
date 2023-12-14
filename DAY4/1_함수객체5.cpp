#include <iostream>
#include <algorithm> 

// 아래 함수 : 비교 정책 교체 가능
// 장점 : 사용자가 정렬 기준 변경 가능
// 단점 : 성능 저하
//		cmp가 inline 함수라도 함수포인터에 담으면 인라인 치환 X

// C 언어 스타일 : 함수 포인터 활용
void Sort(int* x, int sz, bool(*cmp)(int, int )) {
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			//if (x[i] > x[j])  
			if(cmp(i, j) == true)
				std::swap(x[i], x[j]);
		}
	}
}

// 여기서 inline 선언해도, 함수 포인터에 담겨서 -> X
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}

