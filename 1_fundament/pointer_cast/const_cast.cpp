#if 0
#include <iostream>
using namespace std;
int main(){
	int i = 10;
	const int &j = i;
	i=20;
	cout<<"i = "<<i<<" "<<"j = "<<j<<endl;

	int &k = const_cast<int&>(j);
	cout<<"k = "<<k<<endl;
	
	const int & w = const_cast<const int&>(k);
//	w = 30; error.
	cout<<"w = "<<w<<endl;

//	const int h = const_cast<const int>(i);
//	cout<<"h = "<<h<<endl;

	return 0;

}
#endif
