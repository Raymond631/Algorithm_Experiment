#include<iostream>
using namespace std;

int S[10][10];//用于保存结果

struct Job
{
	int id;//作业编号
	int time;//作业所需时间
};
struct Index
{
	int p;//已分配位置索引
	int t;//已分配时长
};

void bubbleSort(Job array[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j].time < array[j + 1].time)//从大到小排序
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
	for (int i = 0; i < m; i++)//所需时间最长的m个作业
	{
		S[i][0] = job[i].id;
		index[i].t = job[i].time;
		index[i].p = 0;//0是第一个位置
	}
	for (int i = m; i < n; i++)//剩下的作业
	{
		//查找最先空闲的机器
		int j = 0;
		for (int k = 1; k < m; k++)
		{
			if (index[k].t<index[j].t)
			{
				j = k;
			}
		}
		index[j].p++;//索引后移

		S[j][index[j].p] = job[i].id;
		index[j].t += job[i].time;//机器已分配时间增加
	}

	for (int i = 0; i < m; i++)
	{
		cout << "机器" << i + 1 << "处理：";
		for (int j = 0; S[i][j] > 0; j++)
		{
			cout << "作业" << S[i][j] << ",";
		}
		cout << "(处理时间：" << index[i].t << ")" << endl;
		cout << endl;
	}
}

int main()
{
	cout << "请输入机器台数：";
	int m;
	cin >> m;

	cout << "请输入作业个数：";
	int n;
	cin >> n;

	cout << "请依次输入每个作业需要的处理时间：";
	Job* job = new Job[n];
	for (int i = 0; i < n; i++)
	{
		job[i].id = i + 1;
		cin >> job[i].time;
	}
	cout << endl;
	bubbleSort(job,n);//从大到小排序

	//索引初始化
	Index* index = new Index[m];
	for (int i = 0; i < m; i++)
	{
		index[i].p = -1;
		index[i].t = 0;
	}

	scheduling(job, index, m, n);//作业分配


	delete[] index;
	delete[] job;
	return 0;
}