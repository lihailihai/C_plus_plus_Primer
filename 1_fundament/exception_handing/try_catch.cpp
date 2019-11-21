#include <iostream>
#include <stdexcept>
using namespace std;
class Sales_item{
	public:
		Sales_item(){
			this->book_number = 0;
		}
		Sales_item(int number){
			this->book_number = number;
		}
		~Sales_item(){
		}
	friend ostream & operator<<( ostream &os, const Sales_item &item){
			os<<"book num:"<<item.book_number<<endl;
			return os;
		}
	friend istream & operator>>(istream &os , Sales_item &item){
			os>>item.book_number;
			return os;
	}
		int isbn(){
			return this->book_number;
		}
	private:
		int book_number;
};
int main(){
	Sales_item item1;
	Sales_item item2;
	while(cin>>item1>>item2){
	cout<<item1<<item2<<endl;
	try{
		if(item1.isbn() != item2.isbn()){
			throw runtime_error("Data must refer to same ISBN");
		}
	}catch(runtime_error err){
		cout<<err.what()
			<<" \nTry Again? Enter y or n"<<endl;
		char c;
		cin>>c;
		if(!cin || c == 'n'){
			break;
		}
	
	}
	}

	return 0;
}
