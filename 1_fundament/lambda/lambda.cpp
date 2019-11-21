#include <iostream>
#include <functional>
using namespace std;
void Test(int a, int b){
 auto f = [a,b](){ return a+b;};
 cout<<f()<<endl;
}

typedef void (*f)(int,int);

void Test2(f fun){
	int a=2,b=3;
	fun(a,b);
}
void Test3(f fun){
	int a=2,b=3;
	fun(a,b);
}
void Test4(std::function<void(int,int)> fun){
	int a=2,b=3;
	fun(a,b);

}

void Test5(int a, int b, int c){
	cout<<"Test5()"<<endl;
}

void Test6(ostream &os,int a, char c='a'){
	cout<<"Test6()"<<endl;
}
int main(){
	static int a = 10;
	const int b = 9;
	int l=100000;
	f test;
	test= Test;
	test(a,b);
	(*test)(a,b);
	Test(2,3);

	Test3([](int c,int d) -> void {cout<<"a:"<<a<<" "<<"b:"<<b<<"c+d:"<<c+d<<endl;});
	Test4([&l](int c,int d) -> void {cout<<"a:"<<a<<" "<<"b:"<<b<<"c+d:"<<c+d<<"l:"<<l<<endl;});

	using std::placeholders::_1;
	using namespace std::placeholders;	
      auto g = bind(Test6,ref(cout),_1,' ');
	Test4(bind(Test5,_1,_2,5));

	Test2(Test);
	Test2(*Test);
	Test2(&Test);
	return 0;
}
