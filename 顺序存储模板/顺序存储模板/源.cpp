#include<iostream>
#include<string>
#include"2.h"
using namespace std;
int main(int argc, char** argv)
{
	int b[5]{ 14,74,78,58,89};
	vector<int>a(b, 5);
	a.erase(3);
	a.insert(2, 77);
	for (int i = 0; i < a.length(); i++)
	{
		cout << a[i] << endl;
	}
}