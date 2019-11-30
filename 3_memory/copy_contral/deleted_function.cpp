#include <iostream>
struct Nocopy{
Nocopy() = default;
Nocopy(const Nocopy& item) = delete;
Nocopy &operator=(const Nocopy & item) = delete;
~Nocopy() = delete;
};
using namespace std;
int main(){
	Nocopy nd;
	Nocopy *p = new Nocopy();
//	delete p;
	return 0;
}
