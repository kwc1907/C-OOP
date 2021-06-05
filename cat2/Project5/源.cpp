#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include"cat head.h"
using namespace std;
int main(int argc, char **argv)
{
	vector<cat>a;
	char n;
	while(1)
	{cout <<"\n"<<"ÇëÊäÈë»Ø³µ:";
	n=getchar();
	if(n!='\n')
	{
		break;
	}
	else
	{
		cat b(n);
		a.push_back(b);
		map<string, int>asd;
		for (auto i : a)
		{
			string t = i.all();
			asd[t]++;
		}
		int f = 1;
		if (asd.size() == 1)
			cout << "they not fight";
		else
		{
			auto i = asd.begin();
			int before = i->second;
			for (; i != asd.end(); i++)
			{
				if (before == i->second)
					continue;
				else { f = 0; break; }
			}
			if (f)
				cout << "they not fight";
			else cout << "they fight";
		}
	}
	}	system("pause");
}