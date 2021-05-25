using namespace std;
template<typename T>
class node
{
public:
	node() { data = 0; next = NULL; prior = NULL; }
	T data;
	node<T>* next,*prior;
};
template<typename T>
class list
{
public:
	list() { first = new node<T>; }
	list(int a[], int n)
	{
		first = new node<T>;
		node<T>*r = first;
		for (int i = 0; i < n; i++)
		{
			node<T>* s = new node<T>;
			s->data = a[i];
			s->next = r->next;
			s->prior =r;
			r->next = s;
			r = s;
		}
		r->next = first;
		first->prior = r;
	}
	int length()
	{
		node<T>* p = first->next;
		int count = 0;
		while (p != first)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	T& operator[](int i)
	{
		node<T>* p = first;
		int count=0;
		while (count<=i)
		{
			count++;
			p = p->next;
		}
		return p->data;
	}
	void insert(int i, T x)
	{
		node<T>* p = first->next;
		int count = 0;
		while (p != first && count < i - 2)
		{
			count++;
			p = p->next;
		}
		if (p == first)
			cout << "wu";
		else
		{
			node<T>* s = new node<T>;
			s->data = x;
			s->prior = p;
			s->next = p->next;
			p->next = s;
			s->next->prior = s;
		}
	}
	void erase(int i)
	{
		node<T>* p = first->next;
		int count = 0;
		while (p != first && count < i - 2 )
		{
			count++;
			p = p->next;
		}
		if (p == first)
			cout << "wu";
		else
		{
			node<T>* s = p->next;
			p->next = s->next;
			s->next->prior = p;
			delete s;
		}
	}
	~list();
private:
	node<T>* first;
};
template<typename T>
list<T>::~list()
{
	node<T>* p = first;
	first = first->next;
	delete p;
}


