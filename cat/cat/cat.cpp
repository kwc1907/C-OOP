#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include"cat head.h"
using namespace std;
int modi(vector<cat>&a)
{
	cout << "是否想要修改猫的数据:";
	string m;
	cin >> m;
	if (m == "yes") {
		while (1)
		{
			cout << "请输入想要修改数据的猫的名字:";
			string na, eyes, furs;
			cin >> na;
			auto t = find_if(a.begin(), a.end(), [na](const cat &i) { return i.name == na; });
			cout << na << "号猫原来数据:";
			price(cout, *t);
			cout << "请输入修改后猫眼睛和皮毛的颜色:";
			cin >> eyes >> furs;
			t->modify(eyes, furs);
			string c;
			cout << "是否想继续修改（是yes，否no）:";
			cin >> c;
			if (c == "yes")
				continue;
			else break;
		}
		return 1;
	}
	return 0;
}
int main(int argc, char **argv)
{
	vector<cat>a;
	string n;
	cout << "请输入猫的名字,end终止输入:";
	while (cin >> n&&n!="end")
	{
		cat b(n);
		a.push_back(b);
	}
	cout << "是否查看猫现在的属性(是:yes 否:no):";
	string o;
	cin >> o;
	if (o == "yes")
	{
		cout << "name" << "\t" << "eye" << "\t" << "fur_colour" << endl;
		for (auto i : a)
			price(cout, i);
	}
	int g=modi(a);
	if (g)
	{
		cout << "name" << "\t" << "eye" << "\t" << "fur_colour" << endl;
		for (const auto &i : a)
			price(cout, i);
	}
	map<string, int>asd;
	for (auto i : a)
	{
		string t=i.all();
		asd[t]++;
	}
	cout<<"是否查看每种猫的数量:";
	string m;
	cin >> m;
	if (m == "yes")
		for (auto i : asd)
			cout << i.first << i.second << endl;
	int f = 1;
	if (asd.size() == 1)
		cout <<"they not fight";
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
	}	system("pause");
}