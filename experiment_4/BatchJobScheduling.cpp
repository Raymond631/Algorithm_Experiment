#include<iostream>
using namespace std;

int number;//作业数量
int x1[10];//作业在机器1运行的时间
int x2[10];//作业在机器2运行的时间
bool vis[10];//作业以否已被选,默认false

int order[10];//作业完成的次序,要用于交换
int sum = 0;//作业完成的总时间
int bestorder[10];//作业完成的最优的顺序
int bestsum = 999;//作业完成的最优时间

int f1 = 0;//机器1累计的时间 
int f2[10];//作业在机器2处理完累计的时间，即每一个作业的调度时间

void backtrack(int cur) //cur表示正在赋值的位置，cur+1去到下一层子节点
{
	if (cur > number)//到达叶子节点，找到一种排列
	{
		for (int i = 1; i <= number; i++)
		{
			bestorder[i] = order[i];
		}
		bestsum = sum;
	}
	else 
	{
		for (int i = 1; i <= number; i++) //遍历当前层的兄弟节点
		{
			if (!vis[i])//未被选中
			{
				vis[i] = true;
				f1 = f1 + x1[i];
				f2[cur] = (f2[cur - 1] > f1 ? f2[cur - 1] : f1) + x2[i];//本作业的在机器1的处理时间 和 上一个作业在机器2的处理时间的较大时间
				sum = sum + f2[cur];
				order[cur] = i;

				//递归
				if (sum < bestsum)
				{
					backtrack(cur + 1);
				}
				//回溯
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
	cout << "请输入作业的数量： ";
	cin >> number;
	cout << "请输入每个作业在机器1的运行时间：";
	for (int i = 1; i <= number; i++)
	{
		cin >> x1[i];
	}
	cout << "请输入每个作业在机器2的运行时间：";
	for (int i = 1; i <= number; i++)
	{
		cin >> x2[i];
	}
	for (int i = 1; i <= number; i++) 	//初始化第一个序列，从1开始到number 
	{
		order[i] = i;
	}
	cout << endl;

	backtrack(1);

	cout << "最节省的时间为：" << bestsum << endl;
	cout << "对应的方案为：";
	for (int i = 1; i <= number; i++)
	{
		cout << bestorder[i] << "  ";
	}
	cout << endl;
}