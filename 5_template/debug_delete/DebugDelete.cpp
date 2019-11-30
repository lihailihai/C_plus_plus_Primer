#include <iostream>
#include <memory>
#include <string>
using namespace std;
class DebugDelete{
	public:
		DebugDelete(std::ostream &s = std::cerr):os(s){}
	template <typename T> void operator()(T *p) const
	{
		os<<"deleting unique_ptr" <<std::endl;
		delete p;
	}
	private:
		std::ostream &os;
};
int main(){
	unique_ptr<int, DebugDelete> p(new int, DebugDelete());
	unique_ptr<string, DebugDelete> g(new string, DebugDelete());
	return 0;
}
