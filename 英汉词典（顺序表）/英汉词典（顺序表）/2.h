const int max = 10000;
using namespace std;
class node
{
public:
	node() = default;
	node(string e, string c):English(e), Chinese(c) {}
	string English;
	string Chinese;
};
class seplist
{
public:
	seplist() { length = 0; };
	void insert(node t)             //Ĭ�ϲ��뵽���Ա�β��
	{
		if (length+1 == max)
			throw "���";
		else
		{
			data[++length] = t;
		}
	}
	string search(string e)         
	{
		int t = search1(e);
		if (t)
			return data[t].Chinese;
		return "���ʲ�����";
	}
	string sort_insert(node t)              //�������
	{
		
		if (length+1== max)
			return "����ʧ�ܣ��ֵ�����";
		else
		{
			int m=length;
			while (data[m].English==" "||data[m].English > t.English)
			{
				data[m + 1] = data[m];
				m--;
			}
			if (data[m].English == t.English)
				return "����ʧ�ܣ������Ѵ���";
			data[m+1] = t;
			length++;
			return "����ɹ�";
		}
	}
	string remove(string e)               //ɾ������
	{
		if (length == 0)
			return "ɾ��ʧ��";
		int t = search1(e);
		if (t == 0)
			return "���ʲ�����";
		else
		{
			while (t != length)
			{
				data[t] = data[t + 1];
				t++;
			}
			length--;
			return "ɾ���ɹ�";
		}
	}
	node& operator[](int i)               //����[]
	{
		return data[i];
	}
	int length;
private:
	node data[max];
	int search1(string e)                 //���ֲ��ҷ��������ҵ�����±�
	{
		int mid, low = 1, high = length;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (e < data[mid].English)high = mid - 1;
			else if (e > data[mid].English) low = mid + 1;
			else return mid;
		}
		return 0;
	}
};