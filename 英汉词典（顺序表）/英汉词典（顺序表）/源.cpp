#include<iostream>
#include<fstream>
#include<string>
#include"2.h"
using namespace std;
string create(seplist& zidian)               //���ֵ�
{
	string t;
	string s;                         
	char ch[50];
	for (char i = 'a'; i <= 'z'; i++)
	{
		s = i;
		s = "d:\\Ӣ���ʵ�\\" + s + ".txt";    //������ĸ��ļ�
		ifstream infile(s, ios::in);
		for (; !infile.eof();)
		{
			int k = 0;
			infile.getline(ch, 50);              //���ļ��л�ȡһ�е���
			int i;
			for (i = 0;i<50; i++)
			{
				if (ch[i] == ' ')
				{
					k = i;                         //��ȡ���ĺ�Ӣ�ķֽ�ĵط�
					break;
				}
			}
			string judgeword(ch);
			if (judgeword.length() != 0) {
				string English = judgeword.substr(0, k);
				string Chinese = judgeword.substr(k + 2);
				node a(English,Chinese);
				zidian.insert(a);                          //���뵽���Ա���
			}
		}
		infile.close();
		node t(" ", " ");                    //�ļ�֮��ķָ�
		zidian.insert(t);
	}
	return "�ʵ�򿪽���";
}
void menu()                                        //����˵�
{
	cout << "_________________________" << endl;
	cout << "|     ʹ��˵��          |" << endl;
	cout << "|1���򿪴ʵ� 2�����ҵ���|" << endl;
	cout << "|3��ɾ������ 4����ӵ���|" << endl;
	cout << "|5���رմʵ�            |" << endl;
	cout << "|���Һ�ɾ��ֻ������Ӣ�� |" << endl;
	cout << "|�����Ҫ�������ĺ�Ӣ�� |" << endl;
	cout << "|_______________________|" << endl;
}
void fun()                       //��֧ѡ��
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
			cout << "����Ӣ�ģ�" << endl;
			cin >> English;
			cout << zidian.search(English) << endl;
		}
	else if (k == 3) {
			cout << "����Ӣ�ģ�" << endl;
			cin >> English;
			cout << zidian.remove(English) << endl;
			flag = 1;
		}
		else if (k == 4) {
			cout <<"����Ӣ��:"<< endl;
			cin >> English;
			cout << "��������:" << endl;
			cin >> Chinese;
			node t(English,Chinese);
			cout << zidian.sort_insert(t) << endl;
			flag = 1;
		}
		else if (k == 5) {
			if (!flag)
				break;
			else                                 //�ֵ䱻�޸ģ�����Ҫ����д��
			{
				int p = 1;
				string s;
				string t;
				for (char i = 'a'; i <= 'z'; i++)
				{
					s = i;
					s = "d:\\Ӣ���ʵ�\\" + s + ".txt";
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
				cout<< "�ݽ����"<<endl;
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