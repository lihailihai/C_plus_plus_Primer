#include <iostream>
using namespace std;
extern void f();
struct X{
	friend void f();
	//friend void f(){
	//	cout<<"Inside friend function f() is called!"<<endl;
	//}	
	X(){
		f();
	}

	void g();
	void h();
};

void X::g(){
	cout<<"In g()===>";
	f();
}

void f(){
	cout<<"Inside friend function f() is called!"<<endl;
}	

void X::h(){
	cout<<"In h()===>";
	h();
}

int main(){
	class X item;
	item.g();
	item.h();
	return 0;
}
