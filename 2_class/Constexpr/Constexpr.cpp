#include <iostream>
using namespace std;
class Debug{
	public:
		Debug() = default;
		constexpr Debug(bool b = true): hw(b),io(b),other(b){};
		constexpr Debug(bool h, bool i, bool ot): hw(h),io(i),other(ot){};
		
		constexpr bool any() {
			return hw || io || other;
		} 

		void set_io(bool b){ io = b;}

		void set_hw(bool b){ hw = b;}

		void set_other(bool b){ other = b;}
	private:
		bool hw;  //hardware error
		bool io;  //input and output error
		bool other; //other error
};

int main(){

	// constexpr function: 
	// 1.return-type must be constexpr
	// 2.input parameters must be constexpr
	// 3.only have one return sentance.

	constexpr Debug io_sub(false,true,false);

	if(io_sub.any()){
		cout<<"io_sub print appropriate error message"<<endl;
	}

	constexpr Debug prod(false);
	if(prod.any()){
		cout<<"prod print appropriate error message"<<endl;
	}
	
	return 0;
}
