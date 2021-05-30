#include<iostream>
#include<string>
using namespace std;
int main(int argc, char argv)
{

	/*//雅可比迭代法:
	int flag = 0;
	int count = 0;
	const int n = 4;
	double a[n][n] = { 5,1,-1,-2,2,8,1,3,1,-2,-4,-1,-1,3,2,7 };
	double b[n] = { -2,-6,6,12 };
	double x[n] = { 0,0,0,0 };
	double x1[n] = { 0,0,0,0 };
	while (!flag)
	{
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (j != i)
				{
					sum += a[i][j] * x[j];
				}
				else continue;
			}
			x1[i] = (b[i] - sum) / a[i][i];
			if (fabs(x[i] - x1[i])>0.001)
			{
				flag =0;
			}
		}
		for (int i = 0; i < n; i++)
			x[i] = x1[i];
		count++;
	}
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
	cout << count;
	//高斯—赛德尔迭代法
	int flag = 0;
	int count = 0;
	const int n = 4;
	double a[n][n] = { 5,1,-1,-2,2,8,1,3,1,-2,-4,-1,-1,3,2,7 };
	double b[n] = { -2,-6,6,12 };
	double x[n] = { 0,0,0,0 };
	double x1[n] = { 0,0,0,0 };
	while (!flag)
	{
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (j != i)
				{
					sum += a[i][j] * x[j];
				}
				else continue;
			}
			x1[i] = (b[i] - sum) / a[i][i];
			if (fabs(x[i] - x1[i]) > 0.001)
			{
				flag = 0;
			}
			x[i] = x1[i];
		}
		count++;
	}
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
	cout << count;*/
	//超松弛迭代法：
	int flag = 0;
	int count = 0;
	const int n = 4;
	double w = 1.15;
	double a[n][n] = { 5,1,-1,-2,2,8,1,3,1,-2,-4,-1,-1,3,2,7 };
	double b[n] = { -2,-6,6,12 };
	double x[n] = { 0,0,0,0 };
	double x1[n] = { 0,0,0,0 };
	while (!flag)
	{
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (j != i)
				{
					sum += a[i][j] * x[j];
				}
				else continue;
			}
			x1[i] = (1-w)*x[i]+w*(b[i] - sum) / a[i][i];
			if (fabs(x[i] - x1[i]) > 0.001)
			{
				flag = 0;
			}
			x[i] = x1[i];
		}
		count++;
	}
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
	cout << count;

}