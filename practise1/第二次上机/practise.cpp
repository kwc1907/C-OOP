#include<iostream>
#include"myinteger.h"
using namespace std;
int main(int argc, char **argv)
{
	myinteger a,b;
	cout << "请输入想要相加的两个对象：";
	a.in();
	b.in();
	a.com(b);
	cout << a.get() <<endl;
	string n;
	cout << "请输入字符串:";
	cin >> n;
	cout << a.parseint(n)<<endl;
	system("pause");
} 