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
	//打开文件
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
	//打开文件
	string accout;
	ifstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "file open error" << endl;
		return -1;
	}
	//读文件
	file.seekg(0, ios::beg);
	cout << "请输入需要查询的账户名" << endl;
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
				cout << "是否需要打印用户账单,请选择输入‘是’或者‘否’。" << endl;
				string bill;
				cin >> bill;
				if (bill == "是")
				{
					string mypath = "F://Account/";
					mypath = mypath + obj_sec.getname() + ".txt";
					ifstream file_b;
					file_b.open(mypath, ios::in);
					if (!file_b)
					{
						cout << "该用户暂时没有账单记录" << endl;

						return -1;
					}
					//读文件
					cout << "账单如下：" << endl;
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
					cout << "请输入密码" << endl;
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
						cout << "是否需要打印用户账单,请选择输入‘是’或者‘否’。" << endl;
						string bill;
						cin >> bill;
						if (bill == "是")
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
							//读文件
							cout << "账单如下：" << endl;
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

						cout << "密码错误，还可以重新输入" << i - 1 << "次密码." << endl;
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
	cout << "用户不存在" << endl;
	file.close();
	return 0;

}
int Withdrawal()
{

	long money;
	long mima;
	while (1)
	{
		cout << "余额" << obj_cur.getmoney() << endl;
		cout << "请输入取款金额(输入0退出):" << endl;
		cin >> money;
		if (0 == money)
		{
			break;
		}
		if (money > obj_cur.getmoney()) //余额
		{
			cout << "余额不足" << endl;
			continue;
		}
		while (1)
		{
			cout << "请输入密码:" << endl;
			cin >> mima;
			if (mima != obj_cur.getpassword())
			{
				cout << "密码错误" << endl;
				continue;
			}
			else break;
		}
		obj_cur.changemoney(obj_cur.getmoney() - money);
		Write_File(obj_cur);
		cout << "存款成功" << endl;
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
		outFile << "取款时间:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " " << endl;
		outFile << "取款：" << money << " " << "余额:" << obj_cur.getmoney() << endl;
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
		cout << "余额" << obj_cur.getmoney() << endl;
		cout << "请输入存款金额(输入0退出):" << endl;
		cin >> money;
		if (0 == money)
		{
			break;
		}
		while (1)
		{
			cout << "请输入密码:" << endl;
			cin >> passwd;
			if (passwd != obj_cur.getpassword())
			{
				cout << "密码错误，请重新输入" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		obj_cur.changemoney(obj_cur.getmoney() + money);
		Write_File(obj_cur);
		cout << "存钱成功" << endl;
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
		outFile << "存款时间:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " " << endl;
		outFile << "存款：" << money << " " << "余额:" << obj_cur.getmoney() << endl;
		outFile.close();
	}
	return 0;
}
int Register()//注册
{
	string name;
	string Account;
	long password;
	string phone;
	string identity;
	long money;
	cout << "请输入您的姓名：";
	cin >> name;
	cout << "请输入用户名：";
	cin >> Account;
	while (1)
	{
		cout << "请输入六位数字密码：";
		cin >> password;
		if (password < 100000 || password>999999)
		{
			cout << "密码格式有有误,请重新输入六位密码" << endl;
			continue;
		}
		break;
	}
	cout << "请输入您的电话号码：";
	cin >> phone;
	cout << "请输入身份ID：";
	cin >> identity;
	cout << "输入存入金额：";
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
	cout << "注册时间:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " ";
	outFile << "注册时间:" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " " << "初始金额：" << obj.getmoney() << endl;
	outFile.close();
	cout << "注册成功" << endl;
	fout.close();
	return 0;
}
int Transfer_Money()
{
	string accout;
	//打开文件
	ifstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "Open File Failed!" << endl;
		return -1;
	}
	//读文件
	file.seekg(0, ios::beg);
	cout << "用户余额:" << obj_cur.getmoney() << endl;
	cout << "请输入对方账户:" << endl;
	cin >> accout;
	while (file.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if ((obj_sec.getAccount() == accout))
		{
			user obj = obj_sec;
			if ((obj_sec.getAccount() == obj_cur.getAccount()))
			{
				cout << "账户不能是当前用户" << endl;
				return -1;
			}
			long money;
			while (1)
			{
				long mima;
				cout << "输入转账金额" << endl;
				cin >> money;
				if (obj_cur.getmoney() < money)
				{
					cout << "余额不足，不能转账" << endl;
					cout << "余额：" << obj_cur.getmoney() << endl;
				}
				while (1)
				{
					cout << "请输入密码:" << endl;
					cin >> mima;
					if (mima != obj_sec.getpassword())
					{
						cout << "密码错误" << endl;
						continue;
					}
					break;
				}
				cout << "余额;" << obj_cur.changemoney(obj_cur.getmoney() - money) << endl;
				obj.changemoney(obj.getmoney() + money);
				Write_File(obj);
				Write_File(obj_cur);
				cout << "转账成功,请及时查询" << endl;
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
				outFile << "转账时间：" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " ";
				outFile << "转账给" << obj.getAccount() << money << " " << "余额:" << obj_cur.getmoney() << endl;
				outFile.close();
				string mypath1 = "F://Account/";
				mypath1 = mypath1 + obj.getname() + ".txt";
				ofstream outFile1(mypath1, ios_base::out | ios_base::app);
				if (!outFile1)
				{
					cout << "File open error" << endl;
				}
				outFile1 << "转账时间：" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " ";
				outFile1 << "收到" << obj_cur.getAccount() << "转账：" << money << " " << "余额:" << obj.getmoney() << endl;
				outFile1.close();
				break;

			}
		}
	}
	return 0;
}
int Login(string &accout, long &passwd, user &obj)
{
	//打开文件
	ifstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "Login Failed!" << endl;
		obj.set();
		return -1;
	}
	//读文件
	file.seekg(0, ios::beg);
	cout << "请输入用户名" << endl;
	cout << "account:";
	cin >> accout;
	while (file.read((char *)&obj, sizeof(obj)))
	{
		if ((obj.getAccount() == accout))
		{
			for (int i = 5; i > 0; i--)
			{
				cout << "请输入密码" << endl;
				cout << "password:";
				cin >> passwd;
				if (obj.getpassword() == passwd)
				{
					cout << "登录成功" << endl;
					file.close();
					return 0;
				}
				else
				{

					cout << "密码错误，还可以重新输入" << i - 1 << "次密码." << endl;
					if (i - 1 <= 0)
					{
						cout << "输入密码次数频繁，十秒后可以重新输入！！！！！" << endl;
						cout << "Waiting--------------";
						Sleep(10000);
						i = 6;
					}
					continue;
				}
			}
		}
	}
	cout << "用户不存在，请注册一个新用户" << endl;
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
	//读文件
	ifile.seekg(0, ios::beg);
	while (ifile.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		if (obj.getAccount() == obj_sec.getAccount())
		{
			continue;
		}
		ofile.seekp(0, ios::beg);
		ofile.write((char *)&obj_sec, sizeof(obj_sec)); //写文件
	}
	ifile.close();
	ofile.close();

	ofstream ofs("F://Register/Register.txt");//清空文件
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
	//读文件
	ifile_r.seekg(0, ios::beg);
	while (ifile_r.read((char *)&obj_sec, sizeof(obj_sec)))
	{
		ofile_r.seekp(0, ios::beg);
		ofile_r.write((char *)&obj_sec, sizeof(obj_sec));
	}
	ifile_r.close();
	ofile_r.close();
	ofstream ofs1("F://temp.txt");//清空文件
	ofs1.close();
	cout << "注销成功" << endl;
	return 0;
}
int Logout1(user &obj)
{
	// 打开文件
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

			cout << "注销成功" << endl;
			return 0;
		}
		count++;
	}
	cout << "注销成功" << endl;
	return 0;
}
int Query_Admi()
{
	//打开文件
	string accout;
	long passwd;
	cout << "请输入需要查询的账户名" << endl;
	cout << "account:";
	cin >> accout;
	cout << "请输入密码" << endl;
	cout << "password:";
	cin >> passwd;
	fstream file;
	file.open("F://Register/Register.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "file open error" << endl;
		return -1;
	}
	//读文件
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
			cout << "用户不存在，请注册一个新用户" << endl;
			file.close();
			return -1;
		}
	}
	file.close();
	return 0;

}

