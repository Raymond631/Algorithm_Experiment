#include<iostream>
using namespace std;

const int n = 8;//�ʺ����
int q[n+1];//���ʺ����ڵ���
int solution = 0;//��ĸ���


bool isSafe(int i, int j)
{
    for (int k = 1; k < i; k++)//������ȷ���Ļʺ�����
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
    if (i > n)////���һ�ֽ������
    {
        cout << "��" << ++solution << "���⣺" << endl;
        for (int i = 1; i <= n; i++)        //��
        {
            for (int j = 1; j <= n; j++)   //��
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
        for (int j = 1; j <= n; j++)//ÿһ��
        {
            if (isSafe(i, j))
            {
                q[i] = j;
                eightQueens(i + 1);  //��ȷ�ϵ� k �лʺ��λ�ú󣬵ݹ������һ�лʺ��λ��
            }
        }
    }
}

int main()
{
	eightQueens(1);
	return 0;
}