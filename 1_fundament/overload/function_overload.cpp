#if 1
#include <iostream>
using namespace std;

int Test(int a, int b, int c=10){
	return a*b*c;
}


// redefined Test() function.
//int Test(int a, int b, int c){
//	return a*b*c;
//}
int Test(int *a){
	cout<<"pointer param is called"<<endl;
	return *a;
}

int Test(const int *a){ //constant-pointer
	cout<<"constant-pointer is called"<<endl;
	return *a;
}
// redefined Test() function
//int Test(int * const a){ //pointer-constant
//	cout<<"pointer-constant is called"<<endl;
//	return *a;
//}

int Test(int &a){
	cout<<"reference param is called"<<endl;
	return a;
}

int Test(const int &a){ //constant-pointer
	cout<<"constant-reference is called"<<endl;
	return a;
}
// redefined Test() function
//int Test(int & const a){ //pointer-constant
//	cout<<"reference-constant is called"<<endl;
//	return a;
//}
/**
 *Inside of class, a const objection can invoke the const-function but not invoke the non-const function, 
 *however, a non-const objection  can invoke both const function and  non-const function where non-function is called first,then calling const function.
 *
 * */
class A{
public:
	int Test(int a, int b , int c=10){
		cout<<"Test() is called"<<endl;
		return a*b*c;
	}
	int Test(int a, int b , int c=10)const{
		cout<<"Test() const is  called"<<endl;
		return a*b*c;
	}
};
int main(){
	constexpr int a = 10;
	cout<<"Test(2,2,2)="<<Test(2,2,2)<<endl;
	cout<<"Test(2,2)="<<Test(2,2)<<endl;
	cout<<"Test(const int a,int b,int c=10)="<<Test(a,2,10)<<endl;

	A b1;
	const A b2;
	b1.Test(10,10);
	b2.Test(10,10);

	int c = 10;
	const int * c1 = &c;
		
	int * const c2 = &c;
	*c2 = 5;
	Test(&c);
	Test(c1);

	int d=10;
	const int & d1 = d;
//	int & const d2 = d; const qualifier is not applied after int &.
	Test(d);
	Test(d1);
	return 0;

}
#endif
