#include<iostream>
using namespace std;

int main()
{
	int N;
	cout << "��������������";
	cin >> N;

	int* h = new int[N];
	cout << "������������У�";
	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
	}

	//�������������
	int* up = new int[N];
	for (int i = 0; i < N; i++)//ÿ��ѭ���У�h[i]Ϊ��ߵ�
	{
		up[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (h[j]<h[i] && (up[j] + 1)>up[i])//��2��������Ϊ���������up[i]
			{
				up[i] = up[j] + 1;
			}
		}
	}

	//����½�������
	int* down = new int[N];
	for (int i = N - 1; i >= 0; i--)//ÿ��ѭ���У�h[i]Ϊ��ߵ�
	{
		down[i] = 1;
		for (int j = N-1; j > i; j--)
		{
			if (h[j]<h[i] && (down[j] + 1)>down[i])//��2��������Ϊ���������up[i]
			{
				down[i] = down[j] + 1;
			}
		}
	}

	//������ܱ���������
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
	cout << "������Ҫ" << N - max << "λͬѧ����" << endl;

	delete[] h;
	delete[] up;
	delete[] down;
	return 0;
}