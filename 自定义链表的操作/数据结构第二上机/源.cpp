#include <iostream>
#include <string>  
#include <vector>  
using namespace std;
class node                         //节点的模板
{
public:
	node() { data = 0; next = NULL; }
	int data;
	node* next;
};
class list                            //链表的模板
{
public:
	list() { first = new node; }
	list(const list& a)               //构造链表
	{
		first = new node;
		node* r = first;
		node* s = a.first->next;
		while (s != NULL)
		{
			node* t = new node;
			t->data = s->data;
			r->next = t;
			r = t;
			s = s->next;
		}
	}
	void inlist()                  //写进链表
	{
		int x;
		node* r = first;
		cin >> x;
		while (x != 0)
		{
			node* s = new node;
			s->data = x;
			r->next = s;
			r = s;
			cin >> x;
		}
	}
	void sort_inlist()             //对链表进行排序
	{
		int n;
		node* r = first;
		cin >> n;
		while (n != 0)
		{
			node* s = new node;
			s->data = n;
			sort_insert(s);
			cin >> n;
		}
	}
	int& operator [](int i)              //重载[]运算符
	{
		node* r = first;
		int count = 0;
		while (count < i)
		{
			r = r->next;
			count++;
		}
		return r->data;
	}
	void bianli()                        //遍历链表
	{ 
		node* r = first->next;
		while (r != NULL)
		{
			cout << r->data << "\t";
			r = r->next;
		}
	}
	void daozhi()                      //倒置操作
	{
		node* s = new node;
		node* r = first->next;
		while (r != NULL)
		{
			node* x = new node;
			x->data = r->data;
			x->next = s->next;
			s->next = x;
			r = r->next;
		}
		desory(first);
		first = s;
	}
	void eraseo()                          //删除偶数操作
	{
		node* r = first;
		while (r != NULL && r->next != NULL)
		{
			if (!(r->next->data % 2))
			{
				node* p = r->next;
				r->next = p->next;
				delete p;
			}
			else
			{
				r = r->next;
			}
		}
	}
	void integer(list a)                        //合并两个链表
	{
		node* m = first;
		node* n = a.first->next;
		while (m->next != NULL && n != NULL)
		{
			if (m->next->data > n->data)
			{

				node* t = n->next;
				n->next = m->next;
				m->next = n;
				n = t;
				m = m->next;
			}
			else
			{
				m = m->next;
			}
		}
		if (m->next == NULL)
		{
			m->next = n;
		}
		a.first = NULL;
	}
	~list()
	{
		desory(first);
	}
private:
	void sort_insert(node* s)                 //对插入后的元素进行排序
	{
		node* r = first;
		if (r->next == NULL)
		{
			r->next = s;
		}
		else
		{
			while (r->next != NULL)
			{
				if (s->data < r->next->data)
				{
					s->next = r->next;
					r->next = s;
					break;
				}
				r = r->next;
			}
			if (r->next == NULL)
			{
				r->next = s;
			}
		}
	}
	void desory(node* first)
	{
		while (first != NULL)
		{
			node* r = first;
			first = first->next;
			delete r;
		}
	}
	node* first;
};

int main(int argc, char** argv)
{
	list a;
	cout << "请输入链表的值(0结束):";
	a.inlist();
	cout << "遍历后的结果:";
	a.bianli();
	cout << "\n倒置后的结果:";
	a.daozhi();
	a.bianli();
	cout << "\n删除偶数后:";
	a.eraseo();
	a.bianli();
	list b;
	cout << "\n请输入要排序链表的值(0结束):";
	b.sort_inlist();
	cout << "排序链表:";
	b.bianli();
	list c, d;
	cout << "\n请输入第一个要排序链表的值(0结束):";
	c.sort_inlist();
	cout << "请输入第二个要排序链表的值(0结束):";
	d.sort_inlist();
	cout << "合成一个为:";
	c.integer(d);
	c.bianli();
}