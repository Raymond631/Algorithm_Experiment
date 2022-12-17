#include<iostream>
using namespace std;

int main()
{
	int N;
	cout << "请输入总人数：";
	cin >> N;

	int* h = new int[N];
	cout << "请输入身高序列：";
	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
	}

	//求最长上升子序列
	int* up = new int[N];
	for (int i = 0; i < N; i++)//每轮循环中，h[i]为最高点
	{
		up[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (h[j]<h[i] && (up[j] + 1)>up[i])//第2个条件是为了求出最大的up[i]
			{
				up[i] = up[j] + 1;
			}
		}
	}

	//求最长下降子序列
	int* down = new int[N];
	for (int i = N - 1; i >= 0; i--)//每轮循环中，h[i]为最高点
	{
		down[i] = 1;
		for (int j = N-1; j > i; j--)
		{
			if (h[j]<h[i] && (down[j] + 1)>down[i])//第2个条件是为了求出最大的up[i]
			{
				down[i] = down[j] + 1;
			}
		}
	}

	//求最多能保留的人数
	int max = 0;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (up[i] + down[i] - 1 > max)
		{
			max = up[i] + down[i] - 1;
			index = i;
		}
	}
	cout << "最少需要" << N - max << "位同学出列" << endl;

	delete[] h;
	delete[] up;
	delete[] down;
	return 0;
}