#include<iostream>
#include<string>
#include<vector>
using namespace std;
string checkpassword()
{
	cout << "���ε����ϵͳ,����������:";
	string word;
	for (int t = 0;; t++)
	{
		int  flag = 0;
		getline(cin, word);
		if (word.size() < 8)
		{
			cout << "����λ������С��8λ,����������:";
			continue;
		}
		for (auto i : word)
		{
			if (!isalnum(i))
			{
				flag = 1;
				cout << "����ֻ�������ֺ���ĸ���ɣ�����������:";
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
			cout << "�������ٰ�����λ���֣�����������:";
			continue;
		}
		cout << "�������óɹ�"<<endl;
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
	cout << "������ѧԺ:";
		cin >> xueyuan;
		cout << "������רҵ:";
		cin >> zhuanye;
		cout << "������ѧ��ѧ�ź�����:";
		for (int i=0; i < student.size(); i++)
		{
			cin >> student[i].num>>student[i].name;
		}
		
}
void output(string &xueyuan,string &zhuanye)
{
	cout << "ѧԺ:"<<xueyuan <<"\n"<<"רҵ:"<< zhuanye<<endl;
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
	cout << "����������:";
	for (int i = 0;; i++)
	{
		getline(cin, a);
		if (a == mima)
		{
			cout << "��Ч����";
			break;
		}
		else {
			cout << "��Ч����" << endl;
			cout << "����������:";
			continue;
		}
	}
	cout << "��ӭ����ѧ������ϵͳ:"<<endl;
	string xueyuan;
	string zhuanye;
   stu student[3];
	input(xueyuan,zhuanye,student);
	output(xueyuan,zhuanye);
	output(student);
	system("pause");
}