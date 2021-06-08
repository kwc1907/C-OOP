using namespace std;
class Rational
{
	friend ostream&operator<<(ostream &os, const Rational &i);
public:
	Rational(double t=0,double n=1) :a(t),b(n) {c = a / b; }
	Rational&operator+=(const Rational &a) { c += a.c; return *this; }
private:
	double a;
	double b;
	double c;
};
ostream&operator<<(ostream &os,const Rational &i)
{
	os << i.c;
	return os;
}
