#include <iostream>
#include <string>
using namespace std;
class Quote{
	public:
		Quote() = default;
		Quote(const string &book, double sales_price):
			bookNo(book),price(sales_price){}
		string isbn() const { return bookNo;}
		virtual double net_price(size_t n) const{ return n * price; }
		virtual ~Quote() = default;
	private:
		string bookNo;
	protected:
		double price = 0.0;
};

class Bulk_quote final: public Quote{
	public:
		Bulk_quote() = default;
		Bulk_quote(const string&, double, size_t, double);
		double net_price(size_t) const override;
	private:
		size_t min_qty = 0;
		double discount = 0.0;
};

Bulk_quote:: Bulk_quote(const string &book, double p, size_t qty, double disc):Quote(book,p),min_qty(qty),discount(disc){}
double Bulk_quote:: net_price(size_t n) const {
	if (n >= min_qty)
		return n * (1 - discount) * price;
	else
		return n * price;
}

int main(){
	Quote base("0-201-84273-1", 50);
	base.net_price(10);
	Bulk_quote derived("5-6768678-353-4", 60,5,.19);
	base.net_price(20);
	return 0;
}
