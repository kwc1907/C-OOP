#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include"cat head.h"
using namespace std;
int modi(vector<cat>&a)
{
	cout << "�Ƿ���Ҫ�޸�è������:";
	string m;
	cin >> m;
	if (m == "yes") {
		while (1)
		{
			cout << "��������Ҫ�޸����ݵ�è������:";
			string na, eyes, furs;
			cin >> na;
			auto t = find_if(a.begin(), a.end(), [na](const cat &i) { return i.name == na; });
			cout << na << "��èԭ������:";
			price(cout, *t);
			cout << "�������޸ĺ�è�۾���Ƥë����ɫ:";
			cin >> eyes >> furs;
			t->modify(eyes, furs);
			string c;
			cout << "�Ƿ�������޸ģ���yes����no��:";
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
	cout << "������è������,end��ֹ����:";
	while (cin >> n&&n!="end")
	{
		cat b(n);
		a.push_back(b);
	}
	cout << "�Ƿ�鿴è���ڵ�����(��:yes ��:no):";
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
	cout<<"�Ƿ�鿴ÿ��è������:";
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