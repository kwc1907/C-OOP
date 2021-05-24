#include <iostream>
#include <string>
#include <fstream>
#include<Windows.h>
using namespace std;
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
class Node           //�������Ľ����
{
public:
	string English;
	string Chinese;
	Node* left;
	Node* right;
};
string search(Node*& root, string English)    //���Ҳ���
{
	if (root == NULL)
		return "���ʲ�����";
	if (English < root->English)
		return search(root->left, English);
	else if (English > root->English)
		return search(root->right, English);
	else
		return root->Chinese;

}
string insert(Node*& root, string English, string Chinese) //�������
{
	if (root == NULL)
	{
		Node* node = new Node;
		node->English = English;
		node->Chinese = Chinese;
		node->left = node->right = NULL;
		root = node;
		return "����ɹ�";
	}
	else if (English < root->English)
		return insert(root->left, English, Chinese);
	else if (English > root->English)
		return insert(root->right, English, Chinese);
	else
		return "����ʧ��";
}
string remove(Node*& root, string English)    //ɾ������ 
{
	if (root == NULL)
		return "ɾ��ʧ��";
	else if (English < root->English)
		return remove(root->left, English);
	else if (English > root->English)
		return remove(root->right, English);
	else                                                      //�ҵ�Ҫɾ���Ľ��
	{
		if ((root->left == NULL) && (root->right == NULL))   //���û�к��ӣ�������ɾ��
		{
			Node* tmp = root;
			root = NULL;
			delete tmp;
		}
		else if ((root->left == NULL) || (root->right == NULL))    //��һ�����ӵ����
		{
			Node* tmp = root;
			if (root->left == NULL)
				root = root->right;
			else
				root = root->left;
			delete tmp;
		}
		else                        //���������ӵ����
		{
			Node* tmp = root->right;
			while (tmp->left != NULL)
				tmp = tmp->left;
			string tmpEnglish = tmp->English;
			string tmpChinese = tmp->Chinese;
			remove(root, tmpEnglish);
			root->English = tmpEnglish;
			root->Chinese = tmpChinese;
		}
		return "ɾ���ɹ�";
	}
}
string create(Node*& root)     //����һ���ֵ�
{
	string t;
	string s;
	char ch[50];
	for (char i = 'a'; i <= 'z'; i++)
	{
		s = i;
		s = "d:\\Ӣ���ʵ�\\" + s + ".txt";
		ifstream infile(s, ios::in);
		for (; !infile.eof();)
		{
			int k = 0;
			infile.getline(ch, 50);
			t = UTF8ToGB(ch);
			int i;
			for (i = 0; t[i] != '\0'; i++)
			{
				if (t[i] == ' ')
				{
					k = i;
					break;
				}
			}
			string judgeword(t);
			if (judgeword.length() != 0) {
				string English = judgeword.substr(0, k);
				string Chinese = judgeword.substr(k + 1);
				insert(root, English, Chinese);
			}
		}
		infile.close();
	}
	return "�ʵ�򿪽���";
}
void menu()
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
void fun()
{
	Node* root = NULL;
	int k;
	string Chinese, English;
	while (true)
	{
		cin >> k;
		if (k == 1)
		{
			cout << create(root) << endl;

		}
		else if (k == 2) {

			cout << "����Ӣ�ģ�" << endl;
			cin >> English;
			cout << search(root, English) << endl;
		}
		else if (k == 3) {
			cout << "����Ӣ�ģ�" << endl;
			cin >> English;
			cout << remove(root, English) << endl;
		}
		else if (k == 4) {
			cout << "����Ӣ�ģ�" << endl;
			cin >> English;
			cout << "�������ģ�" << endl;
			cin >> Chinese;
			cout << insert(root, English, Chinese) << endl;
		}
		else if (k == 5) {
			break;
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