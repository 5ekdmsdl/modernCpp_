// 3_부분특수화1 - 156 p
#include <iostream>

// 기본 틀 만들고, 
// 상속 받아서 특수화 마다 세부 구현 반복 X
class Base {};

// primary template
template<typename T> class Stack : Base
{
public:
	void push(T a) { std::cout << "T" << std::endl; }
};

// partial specialization (부분 특수화)
template<typename T> class Stack<T*> 
{
public:
	void push(T a) { std::cout << "T*" << std::endl; }
};

// specialization (특수화)
template<> class Stack<char*>
{
public:
	void push(char* a) { std::cout << "char*" << std::endl; }
};

// 실제로 찍어낸 객체에 따라서만 template 사용됨
// 특수화로 인한 오버헤드 X

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}



