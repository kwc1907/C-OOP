#include<iostream>
#include<string>
#include<vector>
using namespace std;
string checkpassword()
{
	cout << "初次登入该系统,请设置密码:";
	string word;
	for (int t = 0;; t++)
	{
		int  flag = 0;
		getline(cin, word);
		if (word.size() < 8)
		{
			cout << "密码位数不能小于8位,请重新设置:";
			continue;
		}
		for (auto i : word)
		{
			if (!isalnum(i))
			{
				flag = 1;
				cout << "密码只能由数字和字母构成，请重新设置:";
				break;
			}
		}
		if (flag)
			continue;
		int count = 0;
		for (auto i : word)
		{
			if (isdigit(i))
				count++;
		}
		if (count < 2)
		{
			cout << "密码至少包含两位数字，请重新设置:";
			continue;
		}
		cout << "密码设置成功"<<endl;
		break;
	}
	return word;

}
struct stu
{
	int num;
	string name;
};
void input(string &xueyuan,string &zhuanye,stu (&student)[3])
{
	cout << "请输入学院:";
		cin >> xueyuan;
		cout << "请输入专业:";
		cin >> zhuanye;
		cout << "请输入学生学号和姓名:";
		for (int i=0; i < student.size(); i++)
		{
			cin >> student[i].num>>student[i].name;
		}
		
}
void output(string &xueyuan,string &zhuanye)
{
	cout << "学院:"<<xueyuan <<"\n"<<"专业:"<< zhuanye<<endl;
}
void output(stu (&student)[3])
{
	for(int i=0;i<student.size();i++)
	cout << student[i].num << "\t" << student[i].name << endl;
}
int main()
{
	string mima,a;
	mima=checkpassword();
	cout << "请输入密码:";
	for (int i = 0;; i++)
	{
		getline(cin, a);
		if (a == mima)
		{
			cout << "有效密码";
			break;
		}
		else {
			cout << "无效密码" << endl;
			cout << "请重新输入:";
			continue;
		}
	}
	cout << "欢迎进入学生管理系统:"<<endl;
	string xueyuan;
	string zhuanye;
   stu student[3];
	input(xueyuan,zhuanye,student);
	output(xueyuan,zhuanye);
	output(student);
	system("pause");
}