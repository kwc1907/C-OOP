#include<iostream>
#include"myinteger.h"
using namespace std;
int main(int argc, char **argv)
{
	myinteger a,b;
	cout << "��������Ҫ��ӵ���������";
	a.in();
	b.in();
	a.com(b);
	cout << a.get() <<endl;
	string n;
	cout << "�������ַ���:";
	cin >> n;
	cout << a.parseint(n)<<endl;
	system("pause");
} 