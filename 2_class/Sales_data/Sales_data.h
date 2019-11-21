#include <iostream>
using namespace std;
using int32_t=int;
using float_t=float;
class Sales_data{
	public:
		friend ostream& operator<<(ostream& out,const Sales_data &item);
		friend istream& operator>>(istream& in, Sales_data &item);
//		Sales_data(int32_t isbn, int32_t trans, float_t unit_price,float_t total_price): isbn(isbn),trans(trans),unit_price(unit_price),total_price(total_price)
//	{
//		cout<<"success"<<endl;
//	};
		Sales_data(int32_t isbn, int32_t trans, float_t unit_price);
		explicit Sales_data(int32_t isbn);
		Sales_data():Sales_data(0,0,0){};
		~Sales_data() = default;

		int32_t Isbn() const;
		Sales_data& combine(const Sales_data& item);
	
		friend Sales_data add(const Sales_data& item1,const Sales_data& irem2);
		friend istream& read(istream & in, Sales_data & item);
		friend ostream& print(ostream & os, const Sales_data &item);


	private:
		int32_t isbn=0;
		int32_t trans=0;
		float_t unit_price=0;;
		float_t total_price=0;
};
