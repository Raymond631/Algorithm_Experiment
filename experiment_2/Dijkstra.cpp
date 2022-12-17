#include <iostream>
using namespace std;

#define INF 999999 //������INT_MAX,��Ϊ���������һ��int����ɸ�����
#define Max 10

int dis[Max];//v1����������·��
bool book[Max];//���ҵ����·���ĵ㼯

typedef struct Graph
{							
	int vex, arc;//����������
	int arcs[Max][Max];//�ڽӾ���
};

void Dijkstra(Graph& G)
{
	for (int i = 1; i <= G.vex; i++)
	{
		dis[i] = G.arcs[1][i];//v1�������ֱ��·��
	}
	book[1] = true;

	for (int i = 2; i <= G.vex; i++)//����G.vex-1��
	{
		//�����
		int min = INF, u = 1;
		for (int j = 1; j <= G.vex; j++)
		{
			if (!book[j] && dis[j] < min) 
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = true;//��ǽڵ�uΪ�Ѽ���

		//ˢ��·������
		for (int j = 1; j <= G.vex; j++)
		{
			if (!book[j] && dis[u] + G.arcs[u][j] < dis[j])
			{
				dis[j] = dis[u] + G.arcs[u][j];		//�������·��ֵ
			}
		}
	}
}

int main()
{
	Graph G;

	cout << "����������ͱ�����";
	cin >> G.vex >> G.arc;//�������������
	for (int i = 1; i <= G.vex; i++)
	{
		for (int j = 1; j <= G.vex; j++)
		{
			if (i == j)
				G.arcs[i][j] = 0;//�Ի��߳���Ϊ0
			else
				G.arcs[i][j] = INF;//������ʼ��Ϊ�����
		}
	}
	cout << "���������Ȩֵ��(�����ʽ����� �յ� Ȩֵ)" << endl;
	int u, v, w;//wΪ��<u,v>��Ȩֵ
	for (int i = 1; i <= G.arc; i++)//�ڽӾ��󸳳�ֵ
	{
		cin >> u >> v >> w;
		G.arcs[u][v] = w;
	}

	Dijkstra(G);//�Ͻ�˹�����㷨

	for (int i = 2; i <= G.vex; i++)
	{
		cout << "v1��v" << i << "�����·��Ϊ��" << dis[i] << endl;
	}

	return 0;
}