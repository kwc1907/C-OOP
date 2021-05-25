#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int>sort2(vector<int>& a, int f, int t, int l)
{
	vector<int>b(3,0);
	int sum = 0;
	int lm = -46566;
	for (int i = t; i >= f; i--)
	{
		sum += a[i];
		if (sum > lm)
		{
			lm = sum;
			b[0] = i;
		}
	}
	sum = 0;
	int rm = -4565;
	for (int i = t+1; i<=l; i++)
	{
		sum += a[i];
		if (sum > rm)
		{
			rm = sum;
			b[1] = i;
		}
	}
	b[2] = rm + lm;
	return b;
}
vector<int> sort1(vector<int>& a, int f, int l)
{
	if (f == l)
	{
		vector<int>b(3,0);
		b[0] = b[1] = f;
		b[2] = a[f];
		return b;
	}
	else
	{
		int t = (f + l) / 2;
		vector<int>q= sort1(a, f, t);
		vector<int>w= sort1(a, t + 1, l);
		vector<int>e = sort2(a, f, t, l);
		if (q[2] >= w[2] && q[2] >= e[2])
		{
			return q;
		}
		else if (w[2] >= e[2] && w[2] >= q[2])
		{
			return w;
		}
		else
		{
			return e;
		}
	}
}
int main(int argc, char** argv)
{
	vector<int>a{ 1,2,5,8,9,6,8,5,3,6,5,2,4 };
	vector<int> b=sort1(a, 0, 12);
	for (auto i : b)
		cout << i << endl;
}
