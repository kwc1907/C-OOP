#include"bank.h"
int main()
{
	string account = " ";
	long password = 0, temp;
	while (1)
	{
		cout << "1----->Login（登录） 2----->Sign In（注册）" << endl;
		cin >> temp;
		if (temp == 1)
		{
			while (1)
			{
				Login(account, password, obj_cur);
				if (obj_cur.getAccount() == account)
				{
					int option;
					while (1)
					{
						cout << "0----->Exit(退出)" << endl;
						cout << "1----->Query（查询）" << endl;
						cout << "2----->Logout（注销）" << endl;
						cout << "3----->Deposit（存款）" << endl;
						cout << "4----->Withdrawal（取款）" << endl;
						cout << "5----->Transfer Accounts（转账）" << endl;
						cout << "请选择所需要的服务:";
						cin >> option;
						switch (option)
						{
						case 0:
							option = 0;
							break;
						case 1:
							Query_Clit();
							break;
						case 2:
							if (Logout(obj_cur) == 0) { option = 0; break; }
							return 0;
						case 3:
							Deposit();
							break;
						case 4:
							Withdrawal();
							break;
						case 5:
							Transfer_Money();
						default:
							break;
						}
						if (option == 0)
						{
							break;
						}
					}
					break;
				}
				else
				{
					break;
				}

			}

		}
		else
		{
			Register();
		}
	}

	return 0;
}