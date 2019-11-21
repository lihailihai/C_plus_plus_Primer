#include <iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"Inside class A constructor"<<endl;
		}
		~A(){
			cout<<"Inside class A destructor"<<endl;
		}
		virtual void Test(){
			cout<<"class A Test()"<<endl;
		}
	 	 void Test2(){
			cout<<"class A Test2()"<<endl;
		}
};

class B :public A{
	public:
		B(){
			cout<<"Inside clsaa B constructor"<<endl;
		}
		~B(){
			cout<<"Inside class B destructor"<<endl;
		}
		void Test(){
			cout<<"class B Test()"<<endl;
		}
		void Test2(){
			cout<<"class B Test2()"<<endl;
		}
};

class C{
	public: 
		void Test(){
			cout<<"class C Test()"<<endl;
		}
};
int main(){
	A* a = new A, *a2 = new A;
	B* b = new B, *b2;
	A* a3 = new B;

	a->Test();
	b->Test();
	a3->Test();
	
	a->Test2();
	b->Test2();
	a3->Test2();
	cout<<"dynamic_cast B* -> A*"<<endl;
	a2->Test();
	a2->Test2();
	a2 = dynamic_cast<A*>(b);
	a2->Test();
	a2->Test2();
	b->Test();
	b->Test2();

	if(a2 != NULL){
		cout<<"dynamic_cast success!"<<endl;
	}else{
		cout<<"dynamic_cast failed!"<<endl;
	}


	b2 = dynamic_cast<B*>(a);
	if(b2 != NULL){
		cout<<"dynamic_cast success!"<<endl;
	}else{
		cout<<"dynamic_cast failed!"<<endl;
	}
	
	cout<<"dynamic_cast:A* a3 = new B   B* b2,  a3->b2:"<<endl;
	a3->Test();
	a3->Test2();
	b2 = dynamic_cast<B*>(a3);
	if(b2 != NULL){
		cout<<"dynamic_cast success!"<<endl;
	}else{
		cout<<"dynamic_cast failed!"<<endl;
	}
	b2->Test();
	b2->Test2();
	
	C* cc = dynamic_cast<C*>(a3);
	if(cc != NULL){
		cout<<"dynamic_cast success!"<<endl;
	}else{
		cout<<"dynamic_cast failed!"<<endl;
	}
	cc->Test();
	return 0;
}
