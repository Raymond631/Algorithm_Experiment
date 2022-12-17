#include <iostream>
using namespace std;

#define INF 999999 //不能用INT_MAX,因为正无穷加上一个int后会变成负无穷
#define Max 10

int dis[Max];//v1到各点的最短路程
bool book[Max];//已找到最短路径的点集

typedef struct Graph
{							
	int vex, arc;//点数、边数
	int arcs[Max][Max];//邻接矩阵
};

void Dijkstra(Graph& G)
{
	for (int i = 1; i <= G.vex; i++)
	{
		dis[i] = G.arcs[1][i];//v1到各点的直达路程
	}
	book[1] = true;

	for (int i = 2; i <= G.vex; i++)//遍历G.vex-1次
	{
		//找最短
		int min = INF, u = 1;
		for (int j = 1; j <= G.vex; j++)
		{
			if (!book[j] && dis[j] < min) 
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = true;//标记节点u为已加入

		//刷新路径长度
		for (int j = 1; j <= G.vex; j++)
		{
			if (!book[j] && dis[u] + G.arcs[u][j] < dis[j])
			{
				dis[j] = dis[u] + G.arcs[u][j];		//更新最短路径值
			}
		}
	}
}

int main()
{
	Graph G;

	cout << "请输入点数和边数：";
	cin >> G.vex >> G.arc;//输入点数、边数
	for (int i = 1; i <= G.vex; i++)
	{
		for (int j = 1; j <= G.vex; j++)
		{
			if (i == j)
				G.arcs[i][j] = 0;//自环线长度为0
			else
				G.arcs[i][j] = INF;//其他初始化为无穷大
		}
	}
	cout << "请输入各边权值：(输入格式：起点 终点 权值)" << endl;
	int u, v, w;//w为边<u,v>的权值
	for (int i = 1; i <= G.arc; i++)//邻接矩阵赋初值
	{
		cin >> u >> v >> w;
		G.arcs[u][v] = w;
	}

	Dijkstra(G);//迪杰斯特拉算法

	for (int i = 2; i <= G.vex; i++)
	{
		cout << "v1到v" << i << "的最短路程为：" << dis[i] << endl;
	}

	return 0;
}