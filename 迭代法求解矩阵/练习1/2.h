using namespace std;
class node
{
public:
	node() { data = 0; next = NULL; }
	int data;
	node* next;
};
class list
{
public:
	list() { first = new node; }
	void inlist()
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
	void sort_inlist()
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
	int& operator [](int i)
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
	void bianli()
	{
		node* r = first->next;
		while (r != NULL)
		{
			cout << r->data << "\t";
			r = r->next;
		}
	}
	void daozhi()
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
	void eraseo()
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
	void integer(list a)
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
		delete a.first;
	}
	~list()
	{
		desory(first);
	}
private:
	void sort_insert(node* s)
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
		while (first->next != NULL)
		{
			node* r = first;
			first = first->next;
			delete r;
		}
		delete first;
	}
	node* first;
};
