#include<iostream>
#include<fstream>
#include<string>
#include"2.h"
using namespace std;
string create(seplist& zidian)               //打开字典
{
	string t;
	string s;                         
	char ch[50];
	for (char i = 'a'; i <= 'z'; i++)
	{
		s = i;
		s = "d:\\英汉词典\\" + s + ".txt";    //具体打开哪个文件
		ifstream infile(s, ios::in);
		for (; !infile.eof();)
		{
			int k = 0;
			infile.getline(ch, 50);              //从文件中获取一行单词
			int i;
			for (i = 0;i<50; i++)
			{
				if (ch[i] == ' ')
				{
					k = i;                         //获取中文和英文分界的地方
					break;
				}
			}
			string judgeword(ch);
			if (judgeword.length() != 0) {
				string English = judgeword.substr(0, k);
				string Chinese = judgeword.substr(k + 2);
				node a(English,Chinese);
				zidian.insert(a);                          //插入到线性表中
			}
		}
		infile.close();
		node t(" ", " ");                    //文件之间的分隔
		zidian.insert(t);
	}
	return "词典打开结束";
}
void menu()                                        //输出菜单
{
	cout << "_________________________" << endl;
	cout << "|     使用说明          |" << endl;
	cout << "|1、打开词典 2、查找单词|" << endl;
	cout << "|3、删除单词 4、添加单词|" << endl;
	cout << "|5、关闭词典            |" << endl;
	cout << "|查找和删除只需输入英文 |" << endl;
	cout << "|添加需要输入中文和英文 |" << endl;
	cout << "|_______________________|" << endl;
}
void fun()                       //分支选择
{
	int flag = 0;
	seplist zidian;
	int k;
	string Chinese, English;
	while (true)
	{
		cin >> k;
		if (k == 1)
		{
			cout << create(zidian) << endl;
		}
		else if (k == 2) {
			cout << "输入英文：" << endl;
			cin >> English;
			cout << zidian.search(English) << endl;
		}
	else if (k == 3) {
			cout << "输入英文：" << endl;
			cin >> English;
			cout << zidian.remove(English) << endl;
			flag = 1;
		}
		else if (k == 4) {
			cout <<"输入英文:"<< endl;
			cin >> English;
			cout << "输入中文:" << endl;
			cin >> Chinese;
			node t(English,Chinese);
			cout << zidian.sort_insert(t) << endl;
			flag = 1;
		}
		else if (k == 5) {
			if (!flag)
				break;
			else                                 //字典被修改，所以要重新写回
			{
				int p = 1;
				string s;
				string t;
				for (char i = 'a'; i <= 'z'; i++)
				{
					s = i;
					s = "d:\\英汉词典\\" + s + ".txt";
					ofstream infile(s, ios::out);
					while (zidian[p].English != " " && p <= zidian.length)
					{
						string m = zidian[p].English + "  " + zidian[p].Chinese;
						infile << m << endl;
						p++;
					}
					p++;
					infile.close();
				}
				cout<< "递交完成"<<endl;
				break;
			}
		}
		else {}
	}
}
int main()
{
	menu();
	fun();
	return 0;
}