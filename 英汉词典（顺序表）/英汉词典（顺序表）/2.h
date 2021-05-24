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
	void insert(node t)             //默认插入到线性表尾部
	{
		if (length+1 == max)
			throw "溢出";
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
		return "单词不存在";
	}
	string sort_insert(node t)              //有序插入
	{
		
		if (length+1== max)
			return "插入失败，字典已满";
		else
		{
			int m=length;
			while (data[m].English==" "||data[m].English > t.English)
			{
				data[m + 1] = data[m];
				m--;
			}
			if (data[m].English == t.English)
				return "插入失败，单词已存在";
			data[m+1] = t;
			length++;
			return "插入成功";
		}
	}
	string remove(string e)               //删除函数
	{
		if (length == 0)
			return "删除失败";
		int t = search1(e);
		if (t == 0)
			return "单词不存在";
		else
		{
			while (t != length)
			{
				data[t] = data[t + 1];
				t++;
			}
			length--;
			return "删除成功";
		}
	}
	node& operator[](int i)               //重载[]
	{
		return data[i];
	}
	int length;
private:
	node data[max];
	int search1(string e)                 //二分查找法，返回找到点的下标
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