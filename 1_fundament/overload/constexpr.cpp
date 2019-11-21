#if 0
#include <iostream>
using namespace std;

constexpr size_t new_sz(){ return 42;}
constexpr size_t scale(size_t cnt){ return new_sz()*cnt;}

int main(){

	constexpr int foo = new_sz();
	cout<<"foo="<<foo<<endl;
	int arr[scale(2)];
//      non-constexpr
//	int i = 10;
//	int arr2[scale(i)];
	return 0;
}
#endif
