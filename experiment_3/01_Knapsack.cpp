#include<iostream>
using namespace std;

const int C = 10;
const int N = 5;
int w[5] = { 2,2,6,5,4 };
int v[5] = { 6,3,5,4,6 };
int result[N+1][C+1] = { 0 };

void knapsack01()			//ע�⣺w[]��v[]���±� ���result[]Ҫ��һ
{
	for (int i = 1.; i <= N; i++)//ÿһ�У�����ÿ����Ʒ
	{
		for (int j = 1; j <= C; j++)//ÿһ�У��������ռ��С��������
		{
			if (j < w[i-1])//װ���µ�ǰ��Ʒ
				result[i][j] = result[i - 1][j];
			else//װ����,�Ƚ�װ��ǰ��װ��������ֵ��ȡ�ϴ���
				result[i][j] = (v[i-1] + result[i - 1][j - w[i-1]]) > result[i - 1][j] ? (v[i - 1] + result[i - 1][j - w[i - 1]]) : result[i - 1][j];
		}
	}
}

void select()			//ע�⣺w[]��v[]���±� ���result[]Ҫ��һ
{
	int n = N;
	int c = C;
	while(n>0)
	{
		if (result[n][c] == result[n - 1][c])//ͬһ�����������δ��ѡ��
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
	cout << "��������Ϊ" << C << "���������Ϊ" << result[N][C] << endl;
	cout << "ѡ���ˣ�";
	select();

	return 0;
}