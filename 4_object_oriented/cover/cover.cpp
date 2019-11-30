#include <iostream>
using namespace std;
class A
{
	    public:
		    void printfSth() {
			cout<<"A::printfsth()"<<endl;
								        }

		    void printfSth(string str){				      

		    	    cout<<"A::printfsth(string str):"<<str<<endl;
									        }

		    void printfSth(int i){ 

		   	    cout<<"A::virtual printfSth(int i):"<<i<<endl;								             

		    }
					     
					     
};
class C:public A
{
	    public:
	//	   using A::printfSth;
		void printfSth(double i){		               
		       	cout<<"C::printfSth(double i):"<<i<<endl;							        }
				     
		void printfSth(int i){		               
		       	cout<<"C::printfSth(int i):"<<i<<endl;							        }
				     
				     
};
 
int main()
{
	 
	 
	C* c=new C();
	c->A::printfSth();
	c->printfSth(1);
	c->printfSth(1.1);
 	delete c;
			     
}
