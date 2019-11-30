#include <iostream>
#include <string>

using namespace std;
template<typename T,typename ...Args>
void foo(const T &t, const Args& ... rest){
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(rest)<<endl;
}

template<typename T>
ostream& print(ostream &os, const T& t){
	return os<<t<<endl;
}

template<typename T, typename ...Args>
ostream & print(ostream &os, const T & t, const Args& ...args){

	os<<t<<",";
	return print(os,args...);
}


int main(){
	int i =0; double d=3.23; string s = "hello, world";
	foo(i,d,s,45);
	foo(i,d,d,s,d,s,100);
	print(cout,i,d,d,d,s,s,100,'c',"hi");
	print(cout,i);
	return 0;
}
