#include"pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"2.h"
using namespace std;
patient output1()
{
	cout << "请输入病人信息\n";
	int num, age;
	string name, gender, department;
	cout << "编号:";
	cin >> num;
	cout << "姓名:";
	cin >> name;
	cout << "性别:";
	cin >> gender;
	cout << "年龄:";
	cin >> age;
	cout << "诊室:";
	cin >> department;
	patient a(num, name, gender, age, department);
	return a;
}
doctor output2()
{
	cout << "请输入医生信息\n";
	int num, age;
	string name, gender, department;
	cout << "编号:";
	cin >> num;
	cout << "姓名:";
	cin >> name;
	cout << "性别:";
	cin >> gender;
	cout << "年龄:";
	cin >> age;
	cout << "诊室:";
	cin >> department;
	doctor a(num, name, gender, age, department);
	return a;
}
void print(people &n)
{
	n.print();
}
int main(int argc, char **argv)
{
	
	patient a = output1();
	doctor b=output2();
	a.seedoctor(b);
	print(a);
	print(b);
}