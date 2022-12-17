#include<iostream>
using namespace std;

const int n = 8;//皇后个数
int q[n+1];//各皇后所在的列
int solution = 0;//解的个数


bool isSafe(int i, int j)
{
    for (int k = 1; k < i; k++)//遍历已确定的皇后坐标
    {
        if (q[k] == j || (i - j) == (k - q[k]) || (i + j) == (q[k] + k))
        {
            return false;
        }
    }
    return true;
}

void eightQueens(int i)
{
    if (i > n)////输出一种解决方案
    {
        cout << "第" << ++solution << "个解：" << endl;
        for (int i = 1; i <= n; i++)        //行
        {
            for (int j = 1; j <= n; j++)   //列
            {
                if (q[i] == j)
                    cout << "Q ";
                else
                    cout << "x ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (int j = 1; j <= n; j++)//每一列
        {
            if (isSafe(i, j))
            {
                q[i] = j;
                eightQueens(i + 1);  //在确认第 k 行皇后的位置后，递归测试下一行皇后的位置
            }
        }
    }
}

int main()
{
	eightQueens(1);
	return 0;
}