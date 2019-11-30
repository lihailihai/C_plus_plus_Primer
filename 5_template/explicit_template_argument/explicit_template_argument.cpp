#include <iostream>
#include <string>

using namespace std;
template<typename T1, typename T2, typename T3>
T1 sum(T2 a, T3 b){
	return a+b;
}
int main(){
	cout<<sum<int>(2,2)<<endl;
	cout<<sum<int>(2.3,3.4)<<endl;
	cout<<sum<float>(2.3,3.4)<<endl;
	return 0;
}
