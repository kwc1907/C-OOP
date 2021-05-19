#include<iostream>
#include<string>
using namespace std;
class sale
{
	friend istream &read(istream &is, sale &i);
	friend ostream &print(ostream &os, sale &i);
public:
	sale(string b = "", int c = 0, double p = 0.0, double s = 0, double a = 0.0) :book(b), price(p), count(c), sum(s), ave(a) {}
	string isbn() const{ return book; }
	void aver();
	void com(sale &i);
	~sale() {};
private:
	string book;
	double price;
	int count;
	double ave;
	double sum;
};
void sale::aver()
{
	ave = sum / count;
}
void sale::com(sale &i)
{
	count += i.count;
	sum += i.sum;
}
istream &read(istream &is, sale &i)
{
	is >> i.book >> i.price >> i.count;
	i.sum = i.price*i.count;
	return is;
}
ostream &print(ostream &os, sale &i)
{
	os << i.book << "\t" << i.count << "\t" << i.sum << "\t" << i.ave << endl;
	return os;
}
