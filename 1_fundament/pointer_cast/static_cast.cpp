#if 0
#include <iostream>
using namespace std;
class A{
public:
	A(){
		cout<<"Iside class A"<<endl;
		double a = 9.8831;
		int i = static_cast<int>(a);
		cout<<"i = "<<i<<endl;
	}

	void Test(){
		cout<<"Inside class A Test()"<<endl;
		char c = 'C';
		int j = static_cast<int>(c);
		cout<<"j = "<< j <<endl;
	}
	~A(){}

};

class B :public A{
	public:  
		B(){
			cout<<"Inside class B"<<endl;

		}
		B(const A*){
		}
};

class C{
	public:
		C(){
			cout<<"Inside class C"<<endl;
		}
		~C(){
		}
};
int main(){

	//basic data type casting. 
	float a = 2.3456;
	double b = 4.56789;
	char ch = 'a';
	int c = static_cast<int>(a);
	int d = static_cast<int>(b);
	int e = static_cast<int>(ch);
	cout<<"float convert into int:"<<a<<"->"<<c<<endl;
	cout<<"double convert into int:"<<b<<"->"<<d<<endl;
	cout<<"char convert into int:"<<ch<<"->"<<e<<endl;

	char c1 = static_cast<char>(98);
	float c2 = static_cast<float>(4);
	double c3 = static_cast<double>(4);
	cout<<"int convert into char:"<<98<<"->"<<c1<<endl;
	cout<<"int convert into float:"<<4<<"->"<<c2<<endl;
	cout<<"int convert into double:"<<4<<"->"<<c3<<endl;

	const float w1 = 10.0;
	const int w2 = 3;
	int  w3 = 9;
// demostration that static_cast not satisfied with parameter of const-attribute. 
//	w2 = static_cast<const int>(w1);
//	cout<<"w2 = "<<w2<<endl;

//	w2 = static_cast<const int>(w3);
//	cout<<"w3 = "<<w3<<endl;

//
	//objection data type casting
	A* a_sample = new A, *a_sample2;
	B* b_sample, *b_sample2 = new B;
	C* c_sample;

	b_sample = static_cast<B*>(a_sample); //inheritance relationship from parent class to subclass which complied is ok in this case. HINT: it's not always right!
	
	b_sample->Test();

	a_sample2 = static_cast<A*>(b_sample2); //inheritance relationship from subclass to parent clsaa is right.
	a_sample2->Test();

//	c_sample = static_cast<C*>(a_sample); //non-inheritance relationship is error

	return 0;
}
#endif
