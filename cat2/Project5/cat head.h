#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
class cat
{
	friend ostream &price(ostream &os, const cat &i);
public:
	char name;
	cat(char d);
	void modify(string a, string b);
	string all();
private:
	string eye, fur, furl;
};
cat::cat(char d =' ')
{
	name = d;
	vector<string>a{ "green","blue","brown" };
	vector<string>b{ "black","gray","brown" };
	vector<string>c{ "long","short" };
	srand(time(0));
	int t = rand() % 3, l = rand() % 2, s = rand() % 3;
	eye = a[t];
	fur = b[s];
	furl = c[l];
}
void cat::modify(string a, string b)
{
	eye = a;
	fur = b;
}
ostream &price(ostream &os, const cat &i)
{
	os << i.name << "\t" << i.eye << "\t" << i.fur << endl;
	return os;
}
string cat::all()
{
	string al = "eyecolour and furcolour is " + eye + " and " + fur + " have:";
	return al;
}

