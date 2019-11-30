#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T> string debug_rep(const T &t){
	ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> string debug_rep(T *p){
	ostringstream ret;
//	ret<<"pointer:"<<p;
	ret <<p;
	if(p)
		ret << " " <<debug_rep(*p);
	else
		ret<<" null pointer";
	return ret.str();
}
string debug_rep(const string &s){
	return '"' + s + '"';
}

template<typename T>
ostream & print(std::ostream& os, const T & t){
	return os<<t<<endl;
}

template<typename T, typename ...Args>
ostream & print(std::ostream & os, const T & t, const Args& ... res){
	os<<t<<",";
	return print(os,res...);
}
template<typename ...Args>
ostream & errorMsg(std::ostream &os, const Args&... rest){
	// print(os,debug_rep(a1),debug_rep(a2),...);
	return print(os, debug_rep(rest)...);
}
int main(){
	errorMsg(cout,"fcnName", "hiali", "xing");

	string s("hi");
	cout<< debug_rep(s) <<endl;
	cout<< debug_rep(&s)<<endl;

	const string *sp = &s;
	cout<< debug_rep(sp)<<endl;

	string s2("hailie");
	cout<< debug_rep(s2)<<endl;
	return 0;
}
