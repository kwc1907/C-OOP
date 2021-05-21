#include<string>
using namespace std;
class myinteger
{
public:
	myinteger(int a);
	int get();
	void com(const myinteger &i);
	int parseint( string i);
	void in();
	~myinteger() {};
private:
	int value;
};
myinteger::myinteger(int a = 0) :value(a) {}
int myinteger::get()
{
	return value;
}
void myinteger::in()
{
	cin >> value;
}
void myinteger::com(const myinteger &i)
{
	value += i.value;
}
int myinteger::parseint( string i)
{
		return static_cast<int>(stod(i));
}