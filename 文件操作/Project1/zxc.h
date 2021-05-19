#include<string>
#include<vector>
using namespace std;
class person
{
public:
	vector<int>a;
	int t;
	void in()
	{
		int i;
		while (cin >> i)
			a.push_back(i);
	}
	void put()
	{
		cout<<t;
		for (auto i : a)
			cout << i << endl;
	}
};