#include<string>
using namespace std;
class wuyong
{
public:
	virtual double mianji() = 0;
	virtual void print() = 0;
};
class juxing :public wuyong
{
	friend istream &read(istream &is, juxing &i);
public:
	juxing(double a = 0, double b = 0) { x = a; y = b; }
	double mianji()override { return x * y; }
private:
	double x, y;
};
istream &read(istream &is, juxing &i)
{
	is >> i.x >> i.y;
	return is;
}
class yuan :public wuyong
{
public:
	yuan(double t = 0):r(t) {}
	double mianji()override { return r * r*3.14; }

private:
	double r;
};
