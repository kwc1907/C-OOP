#include <iostream>
#include <string>  
#include <vector>  
#include<random>
using namespace std;
int main(int argc, char** argv)
{
	const int n = 4;
	double a[n][n] = {5,1,-1,-2,2,8,1,3,1,-2,-4,-1,-1,3,2,7};
	double b[n] = {-2,-6,6,12};
	double x[n];
	for (int k = 0; k < n - 1; k++)
	{
		int t=0;
		double max = a[k][k];
		for (int i = k + 1; i < n; i++)
		{
			if (fabs(max) < fabs(a[i][k]))
			{
				t = i;
				max = a[i][k];
			}
		}
		if (t)
		{
			for (int j = k; j < n; j++)
				swap(a[t][j],a[k][j]);
			swap(b[t], b[k]);
		}
		for (int i = k + 1; i < n; i++)
		{
			double m = a[i][k] / a[k][k];
				for (int j = k;j < n; j++)
				{
					a[i][j] -= a[k][j] * m;
				}
				b[i] -= b[k] * m;
		}
	}
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		double t=0;
		for (int j = n - 1; j > i; j--)
		{
			t += x[j] * a[i][j];
		}
		x[i] = (b[i] - t) / a[i][i];
	}
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
}
