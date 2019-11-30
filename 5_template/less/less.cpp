#include <iostream>
#include <functional>
using namespace std;
template<typename A, typename B, typename U = less<int>>
inline bool m(A a, B b, U u = U()){
	return u(a,b);
}
int main(){
//	cout<<less<int>(11,12)<<endl;
	cout<<less<int>()(11,12)<<endl;
	cout<<m(10,12)<<endl;
	
	return 0;
}
