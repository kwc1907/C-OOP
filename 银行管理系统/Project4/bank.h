#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<windows.h>
using namespace std;
class user
{
private:
	long money;
	string name;
	string Account;
	long password;
	string phone;
	string identity;

public:

	user()
	{


	}
	user(string a, string b, long c, string d, string e, long f) :name(a), Account(b), password(c), phone(d), identity(e)
	{
		money = f;
	}
	~user() {};
	string getname()
	{
		return name;
	}
	string getAccount()
	{
		return Account;
	}
	long getpassword()
	{
		return password;
	}
	string getphone()
	{
		return phone;
	}
	string getidentity()
	{
		return identity;
	}
	long getmoney()
	{
		return money;
	}
	long changemoney(long a)
	{
		money = a;
		return money;
	}
	void set()
	{
		name = "";
		Account = "";
		password = 0;
		phone = "";
		identity = "";
		money = 0;
	}

};
user obj_cur, obj_sec;
int Write_File(user &obj)
{
	//���ļ�
	fstream fio;
	fio.open("F://Register/Register.txt", ios::in | ios::out | ios::binary);
	if (!fio)
	{
		cout << " Open File Failed!" << endl;
		return -1;
	}
	fio.seekg(0, ios::beg);
	int count = 0;
	while (fio.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if ((obj.getAccount() == obj_sec.getAccount()))
		{
			fio.seekp(count * sizeof(obj_sec), ios::beg);
			fio.write((char*)&obj, sizeof(obj));
			fio.close();
			return 0;
		}
		count++;
	}

	return 0;
}
int Query_Clit()
{
	//���ļ�
	string accout;
	ifstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "file open error" << endl;
		return -1;
	}
	//���ļ�
	file.seekg(0, ios::beg);
	cout << "��������Ҫ��ѯ���˻���" << endl;
	cout << "account:";
	cin >> accout;
	while (file.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if (obj_sec.getAccount() == accout)
		{
			if (obj_cur.getname() == obj_sec.getname())
			{
				cout << "name=" << obj_sec.getname() << endl;
				cout << "Account=" << obj_sec.getAccount() << endl;
				cout << "password=" << obj_sec.getpassword() << endl;
				cout << "phone=" << obj_sec.getphone() << endl;
				cout << "identity=" << obj_sec.getidentity() << endl;
				cout << "money=" << obj_sec.getmoney() << endl;
				cout << "�Ƿ���Ҫ��ӡ�û��˵�,��ѡ�����롮�ǡ����ߡ��񡯡�" << endl;
				string bill;
				cin >> bill;
				if (bill == "��")
				{
					string mypath = "F://Account/";
					mypath = mypath + obj_sec.getname() + ".txt";
					ifstream file_b;
					file_b.open(mypath, ios::in);
					if (!file_b)
					{
						cout << "���û���ʱû���˵���¼" << endl;

						return -1;
					}
					//���ļ�
					cout << "�˵����£�" << endl;
					char buf;
					file_b.seekg(0, ios::beg);
					while (file_b.eof() == 0)
					{
						file_b.get(buf);
						cout << buf;
					}
					file_b.close();
				}
				file.close();
				return 0;
			}
			else
			{
				long passwd;
				for (int i = 5; i > 0; i--)
				{
					cout << "����������" << endl;
					cout << "password:";
					cin >> passwd;
					if (obj_sec.getpassword() == passwd)
					{
						cout << "name=" << obj_sec.getname() << endl;
						cout << "Account" << obj_sec.getAccount() << endl;
						cout << "password=" << obj_sec.getpassword() << endl;
						cout << "phone=" << obj_sec.getphone() << endl;
						cout << "identity=" << obj_sec.getidentity() << endl;
						cout << "money=" << obj_sec.getmoney() << endl;
						cout << "�Ƿ���Ҫ��ӡ�û��˵�,��ѡ�����롮�ǡ����ߡ��񡯡�" << endl;
						string bill;
						cin >> bill;
						if (bill == "��")
						{
							string mypath = "F://Account/";
							mypath = mypath + obj_sec.getname() + ".txt";
							ifstream file_b;
							file_b.open(mypath, ios::in);
							if (!file_b)
							{
								cout << "file open error" << endl;
								return -1;
							}
							//���ļ�
							cout << "�˵����£�" << endl;
							char buf;
							file_b.seekg(0, ios::beg);
							while (file_b.eof() == 0)
							{
								file_b.get(buf);
								cout << buf;
							}
							file_b.close();
						}
						file.close();
						break;
					}
					else
					{

						cout << "������󣬻�������������" << i - 1 << "������." << endl;
						if (i - 1 <= 0)
						{
							Sleep(3000);
							i = 6;
						}
						continue;
					}
				}

				return 0;
			}
		}
	}
	cout << "�û�������" << endl;
	file.close();
	return 0;

}
int Withdrawal()
{

	long money;
	long mima;
	while (1)
	{
		cout << "���" << obj_cur.getmoney() << endl;
		cout << "������ȡ����(����0�˳�):" << endl;
		cin >> money;
		if (0 == money)
		{
			break;
		}
		if (money > obj_cur.getmoney()) //���
		{
			cout << "����" << endl;
			continue;
		}
		while (1)
		{
			cout << "����������:" << endl;
			cin >> mima;
			if (mima != obj_cur.getpassword())
			{
				cout << "�������" << endl;
				continue;
			}
			else break;
		}
		obj_cur.changemoney(obj_cur.getmoney() - money);
		Write_File(obj_cur);
		cout << "���ɹ�" << endl;
		time_t tt = time(NULL);
		struct tm t;
		localtime_s(&t, &tt);
		string mypath = "F://Account/";
		mypath = mypath + obj_cur.getname() + ".txt";
		ofstream outFile(mypath, ios_base::out | ios_base::app);
		if (!outFile)
		{
			cout << "File open error" << endl;
		}
		outFile << "ȡ��ʱ��:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " " << endl;
		outFile << "ȡ�" << money << " " << "���:" << obj_cur.getmoney() << endl;
		outFile.close();

	}
	return 0;
}
int Deposit()
{
	long money;
	long passwd;
	while (1)
	{
		cout << "���" << obj_cur.getmoney() << endl;
		cout << "����������(����0�˳�):" << endl;
		cin >> money;
		if (0 == money)
		{
			break;
		}
		while (1)
		{
			cout << "����������:" << endl;
			cin >> passwd;
			if (passwd != obj_cur.getpassword())
			{
				cout << "�����������������" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		obj_cur.changemoney(obj_cur.getmoney() + money);
		Write_File(obj_cur);
		cout << "��Ǯ�ɹ�" << endl;
		time_t tt = time(NULL);
		struct tm t;
		localtime_s(&t, &tt);
		string mypath = "F://Account/";
		mypath = mypath + obj_cur.getname() + ".txt";
		ofstream outFile(mypath, ios_base::out | ios_base::app);
		if (!outFile)
		{
			cout << "File open error" << endl;
		}
		outFile << "���ʱ��:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " " << endl;
		outFile << "��" << money << " " << "���:" << obj_cur.getmoney() << endl;
		outFile.close();
	}
	return 0;
}
int Register()//ע��
{
	string name;
	string Account;
	long password;
	string phone;
	string identity;
	long money;
	cout << "����������������";
	cin >> name;
	cout << "�������û�����";
	cin >> Account;
	while (1)
	{
		cout << "��������λ�������룺";
		cin >> password;
		if (password < 100000 || password>999999)
		{
			cout << "�����ʽ������,������������λ����" << endl;
			continue;
		}
		break;
	}
	cout << "���������ĵ绰���룺";
	cin >> phone;
	cout << "���������ID��";
	cin >> identity;
	cout << "��������";
	cin >> money;
	user obj(name, Account, password, phone, identity, money);
	ofstream fout("F://Register/Register.txt", ios::app | ios::binary);
	if (!fout)
	{
		cout << " Open File Failed!" << endl;
		return -1;
	}
	fout.write((char*)&obj, sizeof(obj));
	time_t tt = time(NULL);
	struct tm t;
	localtime_s(&t, &tt);
	string mypath = "F://Account/";
	mypath = mypath + obj.getname() + ".txt";
	ofstream outFile(mypath, ios_base::out | ios_base::app);
	if (!outFile)
	{
		cout << "File open error" << endl;
	}
	cout << "ע��ʱ��:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " ";
	outFile << "ע��ʱ��:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " " << "��ʼ��" << obj.getmoney() << endl;
	outFile.close();
	cout << "ע��ɹ�" << endl;
	fout.close();
	return 0;
}
int Transfer_Money()
{
	string accout;
	//���ļ�
	ifstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "Open File Failed!" << endl;
		return -1;
	}
	//���ļ�
	file.seekg(0, ios::beg);
	cout << "�û����:" << obj_cur.getmoney() << endl;
	cout << "������Է��˻�:" << endl;
	cin >> accout;
	while (file.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if ((obj_sec.getAccount() == accout))
		{
			user obj = obj_sec;
			if ((obj_sec.getAccount() == obj_cur.getAccount()))
			{
				cout << "�˻������ǵ�ǰ�û�" << endl;
				return -1;
			}
			long money;
			while (1)
			{
				long mima;
				cout << "����ת�˽��" << endl;
				cin >> money;
				if (obj_cur.getmoney() < money)
				{
					cout << "���㣬����ת��" << endl;
					cout << "��" << obj_cur.getmoney() << endl;
				}
				while (1)
				{
					cout << "����������:" << endl;
					cin >> mima;
					if (mima != obj_sec.getpassword())
					{
						cout << "�������" << endl;
						continue;
					}
					break;
				}
				cout << "���;" << obj_cur.changemoney(obj_cur.getmoney() - money) << endl;
				obj.changemoney(obj.getmoney() + money);
				Write_File(obj);
				Write_File(obj_cur);
				cout << "ת�˳ɹ�,�뼰ʱ��ѯ" << endl;
				time_t tt = time(NULL);
				struct tm t;
				localtime_s(&t, &tt);
				string mypath = "F://Account/";
				mypath = mypath + obj_cur.getname() + ".txt";
				ofstream outFile(mypath, ios_base::out | ios_base::app);
				if (!outFile)
				{
					cout << "File open error" << endl;
				}
				outFile << "ת��ʱ�䣺" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " ";
				outFile << "ת�˸�" << obj.getAccount() << money << " " << "���:" << obj_cur.getmoney() << endl;
				outFile.close();
				string mypath1 = "F://Account/";
				mypath1 = mypath1 + obj.getname() + ".txt";
				ofstream outFile1(mypath1, ios_base::out | ios_base::app);
				if (!outFile1)
				{
					cout << "File open error" << endl;
				}
				outFile1 << "ת��ʱ�䣺" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " ";
				outFile1 << "�յ�" << obj_cur.getAccount() << "ת�ˣ�" << money << " " << "���:" << obj.getmoney() << endl;
				outFile1.close();
				break;

			}
		}
	}
	return 0;
}
int Login(string &accout, long &passwd, user &obj)
{
	//���ļ�
	ifstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "Login Failed!" << endl;
		obj.set();
		return -1;
	}
	//���ļ�
	file.seekg(0, ios::beg);
	cout << "�������û���" << endl;
	cout << "account:";
	cin >> accout;
	while (file.read((char *)&obj, sizeof(obj)))
	{
		if ((obj.getAccount() == accout))
		{
			for (int i = 5; i > 0; i--)
			{
				cout << "����������" << endl;
				cout << "password:";
				cin >> passwd;
				if (obj.getpassword() == passwd)
				{
					cout << "��¼�ɹ�" << endl;
					file.close();
					return 0;
				}
				else
				{

					cout << "������󣬻�������������" << i - 1 << "������." << endl;
					if (i - 1 <= 0)
					{
						cout << "�����������Ƶ����ʮ�������������룡��������" << endl;
						cout << "Waiting--------------";
						Sleep(10000);
						i = 6;
					}
					continue;
				}
			}
		}
	}
	cout << "�û������ڣ���ע��һ�����û�" << endl;
	file.close();
	obj.set();
	return 0;
}
int Logout(user &obj)
{
	user obj_sec;
	ifstream ifile;
	ifile.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!ifile)
	{
		cout << "file open error" << endl;
		return -1;
	}
	ofstream ofile;
	ofile.open("F://temp.txt", ios::out | ios::binary);
	if (!ofile)
	{
		cout << "file open error" << endl;
		return -1;
	}
	//���ļ�
	ifile.seekg(0, ios::beg);
	while (ifile.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if (obj.getAccount() == obj_sec.getAccount())
		{
			continue;
		}
		ofile.seekp(0, ios::beg);
		ofile.write((char *)&obj_sec, sizeof(obj_sec)); //д�ļ�
	}
	ifile.close();
	ofile.close();

	ofstream ofs("F://Register/Register.txt");//����ļ�
	ofs.close();


	ofstream ofile_r;
	ofile_r.open("F://Register/Register.txt", ios::out | ios::binary);
	if (!ofile_r)
	{
		cout << "file open error" << endl;
		return -1;
	}
	ifstream ifile_r;
	ifile_r.open("F://temp.txt", ios::in | ios::binary);
	if (!ifile_r)
	{
		cout << "file open error" << endl;
		return -1;
	}
	//���ļ�
	ifile_r.seekg(0, ios::beg);
	while (ifile_r.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		ofile_r.seekp(0, ios::beg);
		ofile_r.write((char *)&obj_sec, sizeof(obj_sec));
	}
	ifile_r.close();
	ofile_r.close();
	ofstream ofs1("F://temp.txt");//����ļ�
	ofs1.close();
	cout << "ע���ɹ�" << endl;
	return 0;
}
int Logout1(user &obj)
{
	// ���ļ�
	fstream fio;
	fio.open("F://Register/Register.txt", ios::in | ios::out | ios::binary);
	if (!fio)
	{
		cout << " Open File Failed!" << endl;
		return -1;
	}
	fio.seekg(0, ios::beg);
	int count = 0;
	char buf[sizeof(obj)] = { 0 };
	while (fio.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if ((obj.getAccount() == obj_sec.getAccount()))
		{
			fio.seekp(count * sizeof(obj_sec), ios::beg);
			fio.write(buf, sizeof(obj));
			fio.close();

			cout << "ע���ɹ�" << endl;
			return 0;
		}
		count++;
	}
	cout << "ע���ɹ�" << endl;
	return 0;
}
int Query_Admi()
{
	//���ļ�
	string accout;
	long passwd;
	cout << "��������Ҫ��ѯ���˻���" << endl;
	cout << "account:";
	cin >> accout;
	cout << "����������" << endl;
	cout << "password:";
	cin >> passwd;
	fstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "file open error" << endl;
		return -1;
	}
	//���ļ�
	file.seekg(0, ios::beg);
	while (file.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if (obj_sec.getAccount() == accout)
		{
			if (obj_sec.getpassword() == passwd)
			{
				cout << "name=" << obj_sec.getname() << endl;
				cout << "Account" << obj_sec.getAccount() << endl;
				cout << "password=" << obj_sec.getpassword() << endl;
				cout << "phone=" << obj_sec.getphone() << endl;
				cout << "identity=" << obj_sec.getidentity() << endl;
				cout << "money=" << obj_sec.getmoney() << endl;
				file.close();
				return 0;
			}

		}
		else
		{
			cout << "�û������ڣ���ע��һ�����û�" << endl;
			file.close();
			return -1;
		}
	}
	file.close();
	return 0;

}

