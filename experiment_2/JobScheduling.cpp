#include<iostream>
using namespace std;

int S[10][10];//���ڱ�����

struct Job
{
	int id;//��ҵ���
	int time;//��ҵ����ʱ��
};
struct Index
{
	int p;//�ѷ���λ������
	int t;//�ѷ���ʱ��
};

void bubbleSort(Job array[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j].time < array[j + 1].time)//�Ӵ�С����
			{
				Job temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void scheduling(Job job[], Index index[], int m, int n)
{
	for (int i = 0; i < m; i++)//����ʱ�����m����ҵ
	{
		S[i][0] = job[i].id;
		index[i].t = job[i].time;
		index[i].p = 0;//0�ǵ�һ��λ��
	}
	for (int i = m; i < n; i++)//ʣ�µ���ҵ
	{
		//�������ȿ��еĻ���
		int j = 0;
		for (int k = 1; k < m; k++)
		{
			if (index[k].t<index[j].t)
			{
				j = k;
			}
		}
		index[j].p++;//��������

		S[j][index[j].p] = job[i].id;
		index[j].t += job[i].time;//�����ѷ���ʱ������
	}

	for (int i = 0; i < m; i++)
	{
		cout << "����" << i + 1 << "����";
		for (int j = 0; S[i][j] > 0; j++)
		{
			cout << "��ҵ" << S[i][j] << ",";
		}
		cout << "(����ʱ�䣺" << index[i].t << ")" << endl;
		cout << endl;
	}
}

int main()
{
	cout << "���������̨����";
	int m;
	cin >> m;

	cout << "��������ҵ������";
	int n;
	cin >> n;

	cout << "����������ÿ����ҵ��Ҫ�Ĵ���ʱ�䣺";
	Job* job = new Job[n];
	for (int i = 0; i < n; i++)
	{
		job[i].id = i + 1;
		cin >> job[i].time;
	}
	cout << endl;
	bubbleSort(job,n);//�Ӵ�С����

	//������ʼ��
	Index* index = new Index[m];
	for (int i = 0; i < m; i++)
	{
		index[i].p = -1;
		index[i].t = 0;
	}

	scheduling(job, index, m, n);//��ҵ����


	delete[] index;
	delete[] job;
	return 0;
}