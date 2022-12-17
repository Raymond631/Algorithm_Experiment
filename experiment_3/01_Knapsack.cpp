#include<iostream>
using namespace std;

const int C = 10;
const int N = 5;
int w[5] = { 2,2,6,5,4 };
int v[5] = { 6,3,5,4,6 };
int result[N+1][C+1] = { 0 };

void knapsack01()			//注意：w[]和v[]的下标 相对result[]要减一
{
	for (int i = 1.; i <= N; i++)//每一行，代表每件物品
	{
		for (int j = 1; j <= C; j++)//每一列，代表背包空间大小递增序列
		{
			if (j < w[i-1])//装不下当前物品
				result[i][j] = result[i - 1][j];
			else//装得下,比较装入前和装入后的最大价值，取较大者
				result[i][j] = (v[i-1] + result[i - 1][j - w[i-1]]) > result[i - 1][j] ? (v[i - 1] + result[i - 1][j - w[i - 1]]) : result[i - 1][j];
		}
	}
}

void select()			//注意：w[]和v[]的下标 相对result[]要减一
{
	int n = N;
	int c = C;
	while(n>0)
	{
		if (result[n][c] == result[n - 1][c])//同一列上下相等则未被选中
		{
			n--;
		}
		else
		{
			cout << "(" << w[n-1] << "," << v[n-1] << ")";
			c = c - w[n-1];
			n--;
		}
	}
	cout << endl;
}

int main()
{
	knapsack01();
	cout << "背包容量为" << C << "，最大收益为" << result[N][C] << endl;
	cout << "选择了：";
	select();

	return 0;
}