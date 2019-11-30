#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;
template <typename it>
auto  fcn(it beg, it end)->decltype(*beg){
	return *beg;
}

template <class It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type{
	return *beg;
}

template<typename T1, typename T2>
int compare(const T1 & it1, const T2 & it2){
	return 1;
}
	void func(int(*) (const string&, const string&)){
		cout<<"string type"<<endl;
	}
	void func(int(*) (const int &, const int &)){
		cout<<"int type"<<endl;
	}
int main(){
	vector<int> vi = {1,2,3,4};
	
	auto rt = fcn(vi.begin(),vi.end());

	cout<<typeid(rt).name()<<endl;
	
	cout<<typeid(vi).name()<<endl;

	auto rt2 = fcn2(vi.begin(), vi.end());
	cout<<typeid(rt2).name()<<endl;


	int (*pf)(const int&, const int&) = compare;

	func(pf);

//	func(compare);
	func(compare<int,int>);
	return 0;
}
