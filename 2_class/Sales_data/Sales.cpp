#include"Sales_data.h"
int main(){
	int32_t a = 6;
	float_t b= 7;
	cout<<a*b<<endl;

	Sales_data *p = new Sales_data(3,3,3);
	cout<<"*p"<<*p<<endl;

	Sales_data qq = Sales_data(3,3,3);
	cout<<"qq"<<qq<<endl;
		
	Sales_data test('c');
	cout<<test<<endl;

	Sales_data item1(3,3,3);
	Sales_data item2(2,2,2);
	cout<<item2<<endl;

	Sales_data item3;
	read(cin,item3);

	cout<<item3<<endl;
	print(cout,item3)<<endl;
	cout<<"Test add()"<<endl;
	Sales_data item4 = add(item2,item3);
	cout<<item4;
	cout<<"Test combine()"<<endl;
	item1.combine(item2);
	cout<<item1<<endl;

	a = item4.Isbn();
	cout<<a<<endl;
	
	const Sales_data item5(6,6,6);
	cout<<item5.Isbn()<<endl;

	//item5.combine(item4); error
	

	return 0;
}
