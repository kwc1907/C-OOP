#include<iostream>
#include<vector>
#include<string>
#include"2.h"
using namespace std;
int main(int argc, char** argv)
{
	int b[4]{ 1,78,58,96 };
	list<int>a(b, 4);
	a.insert(2, 5);
	a.erase(3);
	for (int i = 0; i < 4; i++)
		cout << a[i] << endl;
	cout << a.length();
}