#include<iostream>
using namespace std;

int number;//��ҵ����
int x1[10];//��ҵ�ڻ���1���е�ʱ��
int x2[10];//��ҵ�ڻ���2���е�ʱ��
bool vis[10];//��ҵ�Է��ѱ�ѡ,Ĭ��false

int order[10];//��ҵ��ɵĴ���,Ҫ���ڽ���
int sum = 0;//��ҵ��ɵ���ʱ��
int bestorder[10];//��ҵ��ɵ����ŵ�˳��
int bestsum = 999;//��ҵ��ɵ�����ʱ��

int f1 = 0;//����1�ۼƵ�ʱ�� 
int f2[10];//��ҵ�ڻ���2�������ۼƵ�ʱ�䣬��ÿһ����ҵ�ĵ���ʱ��

void backtrack(int cur) //cur��ʾ���ڸ�ֵ��λ�ã�cur+1ȥ����һ���ӽڵ�
{
	if (cur > number)//����Ҷ�ӽڵ㣬�ҵ�һ������
	{
		for (int i = 1; i <= number; i++)
		{
			bestorder[i] = order[i];
		}
		bestsum = sum;
	}
	else 
	{
		for (int i = 1; i <= number; i++) //������ǰ����ֵܽڵ�
		{
			if (!vis[i])//δ��ѡ��
			{
				vis[i] = true;
				f1 = f1 + x1[i];
				f2[cur] = (f2[cur - 1] > f1 ? f2[cur - 1] : f1) + x2[i];//����ҵ���ڻ���1�Ĵ���ʱ�� �� ��һ����ҵ�ڻ���2�Ĵ���ʱ��Ľϴ�ʱ��
				sum = sum + f2[cur];
				order[cur] = i;

				//�ݹ�
				if (sum < bestsum)
				{
					backtrack(cur + 1);
				}
				//����
				order[cur] = -1;
				sum = sum - f2[cur];
				f2[cur] = 0;
				f1 = f1 - x1[i];
				vis[i] = false;
			}
		}
	}
}

int main() 
{
	cout << "��������ҵ�������� ";
	cin >> number;
	cout << "������ÿ����ҵ�ڻ���1������ʱ�䣺";
	for (int i = 1; i <= number; i++)
	{
		cin >> x1[i];
	}
	cout << "������ÿ����ҵ�ڻ���2������ʱ�䣺";
	for (int i = 1; i <= number; i++)
	{
		cin >> x2[i];
	}
	for (int i = 1; i <= number; i++) 	//��ʼ����һ�����У���1��ʼ��number 
	{
		order[i] = i;
	}
	cout << endl;

	backtrack(1);

	cout << "���ʡ��ʱ��Ϊ��" << bestsum << endl;
	cout << "��Ӧ�ķ���Ϊ��";
	for (int i = 1; i <= number; i++)
	{
		cout << bestorder[i] << "  ";
	}
	cout << endl;
}