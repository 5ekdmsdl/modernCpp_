// 14_override  - 44 page

class Base {
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base {
public:
	// 가상 함수 재정의시 실수(오타) 발생해도 컴파일 에러 X
	// => 컴파일러 : 그냥 새로 만들었나보다~~
	/*virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
	*/
	
	// => Cpp11 부터 override 키워드 제공!
	virtual void fooo() override {}
	virtual void goo(double a) override  {}
	virtual void hoo() const  override {}
	// compiler가 error 찾아준다.

};

int main() {



}