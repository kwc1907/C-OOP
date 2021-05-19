#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<list>
#include<algorithm>
#include<numeric>
#include<functional>
#include<iterator>
using namespace std;
using namespace placeholders;
int main(int argc, char **argv)
{
	ifstream file("f2.txt",ios::in);
	ofstream file1("f1.txt",ios::out);
	ofstream file2("f3.txt",ios::out);
	if (!file1) { cout << "cuowu"; }
	istream_iterator<int>a(file);
	istream_iterator<int>e;
	vector<int>b(a,e);
	ostream_iterator<int>o(file1, "\n");
	ostream_iterator<int>o1(file2, "\n");
	for (auto &i : b)
	{
		if (i % 2==1)
			*o++ = i;
		else *o1++ = i;
	}
	system("pause");
}