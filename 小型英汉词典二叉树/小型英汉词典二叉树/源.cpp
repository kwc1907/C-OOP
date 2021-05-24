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

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
class Node           //二叉树的结点类
{
public:
	string English;
	string Chinese;
	Node* left;
	Node* right;
};
string search(Node*& root, string English)    //查找操作
{
	if (root == NULL)
		return "单词不存在";
	if (English < root->English)
		return search(root->left, English);
	else if (English > root->English)
		return search(root->right, English);
	else
		return root->Chinese;

}
string insert(Node*& root, string English, string Chinese) //插入操作
{
	if (root == NULL)
	{
		Node* node = new Node;
		node->English = English;
		node->Chinese = Chinese;
		node->left = node->right = NULL;
		root = node;
		return "插入成功";
	}
	else if (English < root->English)
		return insert(root->left, English, Chinese);
	else if (English > root->English)
		return insert(root->right, English, Chinese);
	else
		return "插入失败";
}
string remove(Node*& root, string English)    //删除操作 
{
	if (root == NULL)
		return "删除失败";
	else if (English < root->English)
		return remove(root->left, English);
	else if (English > root->English)
		return remove(root->right, English);
	else                                                      //找到要删除的结点
	{
		if ((root->left == NULL) && (root->right == NULL))   //如果没有孩子，就正常删除
		{
			Node* tmp = root;
			root = NULL;
			delete tmp;
		}
		else if ((root->left == NULL) || (root->right == NULL))    //有一个孩子的情况
		{
			Node* tmp = root;
			if (root->left == NULL)
				root = root->right;
			else
				root = root->left;
			delete tmp;
		}
		else                        //有两个孩子的情况
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
		return "删除成功";
	}
}
string create(Node*& root)     //创建一个字典
{
	string t;
	string s;
	char ch[50];
	for (char i = 'a'; i <= 'z'; i++)
	{
		s = i;
		s = "d:\\英汉词典\\" + s + ".txt";
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
	return "词典打开结束";
}
void menu()
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

			cout << "输入英文：" << endl;
			cin >> English;
			cout << search(root, English) << endl;
		}
		else if (k == 3) {
			cout << "输入英文：" << endl;
			cin >> English;
			cout << remove(root, English) << endl;
		}
		else if (k == 4) {
			cout << "输入英文：" << endl;
			cin >> English;
			cout << "输入中文：" << endl;
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