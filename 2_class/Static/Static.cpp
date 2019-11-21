#include <iostream>
#include <string>
using namespace std;

class Account{
	public:
		Account() = default;
		
		Account(string name,double at):owner(name), amount(at){}
		
		friend ostream& operator<<(ostream &os, const Account & item){
			os<<"name:"<<item.owner<<" "<<"amount:"<<item.amount<<" "<<endl;
			return os;
		}

		void calculate(){
		       amount += amount * interestRate;	       
		}

		void Test(){
			cout<<"Inside Test function"<<period<<endl;
		}

		static double rate(){ 
			return interestRate;
		}
	
		static void rate(double newRate);
	
	private:
		static double interestRate;
		static constexpr int period = 30;
		double daily_tbl[period];	
		string owner;
		double amount;
		static int test;
		static double initRate();
};

double Account::interestRate = 10;

int Account::test = 10;
constexpr int Account::period; 

void Account::rate(double newRate){
	interestRate = newRate;
}

double Account::initRate(){
	interestRate = 5; 
}

//double Account::interestRate = Account::initRate();

//private
//Account:: interestRate = 10;

int main(){
	
	constexpr int d= 10;

	Account::rate();
	
	double r = Account::rate();
	cout<<"r= "<<r<<endl;

	Account item("haili",1000);
	cout<<item<<endl;
	
	item.Test();	

	return 0;
}
