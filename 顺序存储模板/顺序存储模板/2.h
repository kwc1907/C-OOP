using namespace std;
template<typename T>
class vector
{
public:
	vector() { lon= 0; max = 15; }
	vector(T a[], int n) 
	{
		max = 15;
		if (n >=max)
			throw"cuowu";
		else
		{
			for (int i = 0; i < n; i++)
				data[i] = a[i];
			lon = n;
		}
	}
	int length() { return lon; }
	T& operator[](int i)
	{
		return data[i];
	}
	void insert(int i, T x)
	{
		if (i >= max)
			throw"cuowu";
		else if (i <1|| i > lon)throw i;
		else
		{
			int t = lon;
			for (; t >= i; t--)
			{
				data[t] = data[t-1];
			}
			data[i-1] = x;
			lon++;
		}
	}
	void erase(int i)
	{
		if (i >= max)
			throw"cuowu";
		else if (i <1 || i > lon)throw i;
		else
		{
			for (int t = i - 1; t < lon-1; t++)
			{
				data[t] = data[t + 1];
			}
			lon--;
		}
	}
private:
	int max;
	T data[15];
	int lon;
};