#include"bank.h"
int main()
{
	string account = " ";
	long password = 0, temp;
	while (1)
	{
		cout << "1----->Login����¼�� 2----->Sign In��ע�ᣩ" << endl;
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
						cout << "0----->Exit(�˳�)" << endl;
						cout << "1----->Query����ѯ��" << endl;
						cout << "2----->Logout��ע����" << endl;
						cout << "3----->Deposit����" << endl;
						cout << "4----->Withdrawal��ȡ�" << endl;
						cout << "5----->Transfer Accounts��ת�ˣ�" << endl;
						cout << "��ѡ������Ҫ�ķ���:";
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