#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<list>
#include<deque>
#include<array>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
#include<functional>
#include"2.h"
using namespace std;
using namespace placeholders;
int main(int argc, char **argv)
{
	vector<sale>a;
	sale b;
	while (read(cin, b))
	{
		auto i = find_if(a.begin(), a.end(), [b](const sale &s1) {return s1.isbn() == b.isbn(); });
		if (i == a.end())
			a.push_back(b);
		else (*i).com(b);
	}
	for (int i = 0; i < a.size(); i++)
	{
		a[i].aver();
		print(cout,a[i]);
	}
	int n;
	cin >> n;
	system("pause");
}