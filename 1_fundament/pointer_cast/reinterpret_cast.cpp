#if 0
#include <iostream>
using namespace std;
int main(){

	int i = 10, *j;
	float k = 4.0, *l;
	j = reinterpret_cast<int*>(i);
	cout<<"j = "<<&j<<endl;

	j = reinterpret_cast<int*>(&k);
	cout<<"j = "<<&j<<endl;
// this is not allowed
//	k = reinterpret_cast<float>(i);
//	cout<<"k = "<<k<<endl;

//	i = reinterpret_cast<int>(k);
//	cout<<"i = "<<i<<endl;
	
	j = reinterpret_cast<int*>(l);
	if(j != NULL){
		cout<<"reinterpret_cast success!"<<endl;
	}else{
		cout<<"reinterpret_cast failed!"<<endl;
	}

	l = reinterpret_cast<float *>(&i);
	if(l != NULL){
		cout<<"reinterpret_cast success!"<<endl;
	}else{
		cout<<"reinterpret_cast failed!"<<endl;
	}

      	return 0;

}
#endif
