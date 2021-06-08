#include<iostream>
#include"2.h"
using namespace std;
int main(int argc, char **argv)
{
	Rational sum;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		double t = i;
		Rational p(i,t+1);
		sum += p;
	}
	cout << sum<<endl;
	system("pause");
}