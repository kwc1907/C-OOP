#include <iostream>
#include <string>  
#include <vector>  
#include<random>
using namespace std;
int sort1(string &a, int f, int q, int l)
{
	string b;
	int i = f, j = q + 1,t=0;
	while (i != q + 1 && j != l + 1)
	{
		if (a[i] > a[j])
		{
			b.push_back(a[j++]);
			t += q - i + 1;
		}
		else
		{
			b.push_back(a[i++]);
		}
	}
	if (i == q + 1)
	{
		while (j != l + 1)
		{
			b.push_back(a[j++]);
		}
	}
	else if(j==l+1)
	{
		while (i != q + 1)
			b.push_back(a[i++]);
	}
	for (auto i : b)
		a[f++] = i;
	return t;
}
int sort(string &a, int f, int l)
{
	if (f < l)
	{
		int q = (f + l) / 2;
		int s1 = sort(a, f, q);
		int s2 = sort(a, q + 1, l);
		int s3 = sort1(a, f, q, l);
		return s1 + s2 + s3;
	}
	else
		return 0;
}
int sort2(vector<string>& a, vector<int>& b, int f,int l)
{
	int j = f - 1;
	for (int i = f; i < l; i++)
	{
		if (b[i] < b[l])
		{
			j++;
			swap(a[j],a[i]);
			swap(b[i],b[j]);
		}
	}
	swap(b[j + 1],b[l]);
	swap(a[j+1],a[l]);
	return j + 1;
}
void sort3(vector<string>&a,vector<int>&b,int f,int l)
{
	if (f < l)
	{
		int q = sort2(a, b, f, l);
		sort3(a,b,f,q-1);
		sort3(a,b,q+1,l);
	}
}
int main(int argc, char** argv)
{
	vector<string>a;
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		string t;
		cin >> t;
		a.push_back(t);
	}
	vector<string>c(a);
	vector<int>b;
	for (int i = 0; i < n; i++)
	{
		int t = sort(a[i],0,m-1);
		b.push_back(t);
	}
	sort3(c, b, 0, n - 1);
	for (auto i : c)
		cout << i <<endl;

}