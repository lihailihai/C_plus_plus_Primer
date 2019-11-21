#include "Sales_data.h"
using int32_t=int;
using float_t=float;

Sales_data::Sales_data(int32_t is, int32_t t, float_t u){
	this->isbn = is;
	this->trans = t;
	this->unit_price = u;
	this->total_price = u*t;

}

Sales_data::Sales_data(int32_t isbn): isbn(isbn){}

int32_t Sales_data::Isbn() const{ return this->isbn;}

ostream& operator<<(ostream& out, const Sales_data &item){
	out<<"isbn: "<<item.isbn<<" "
		<<"trans: "<<item.trans<<" "
		<<"total_price: "<<item.total_price<<" "
		<<"unit_price "<<item.unit_price<<endl;
	return out;

}

istream& operator>>(istream& in, Sales_data& item){
	in>>item.isbn>>item.trans
		>>item.unit_price
		>>item.total_price;
	return in;
}

Sales_data& Sales_data::combine(const Sales_data& item){
	this->trans += item.trans;
	this->total_price += item.total_price;
	return *this;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2){
	Sales_data ite = item1;
	ite.combine(item2);
	return ite;
}

istream& read(istream & in, Sales_data & item){
	in>>item;
	return in;
}

ostream& print(ostream& os, const Sales_data& item){
	os<<item;
	return os;
}
