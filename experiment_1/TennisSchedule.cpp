#include <iostream>
using namespace std;
 
const int N=8;
 
void table(int a[][N+1], int n, int temp)
{
    int i, j;
    if (n == 2)
    {
        a[1][1] = 1;
        a[1][2] = 2;
        a[2][1] = 2;
        a[2][2] = 1;
    }
    else
    {
        temp = temp / 2;
        table(a, n / 2, temp);

        //�����½�
        for (i = temp + 1; i <= n; i++)
            for (j = 1; j <= temp; j++)
                a[i][j] = a[i - temp][j] + temp;
        //�����Ͻ�
        for (i = 1; i <= temp; i++)
            for (j = temp + 1; j <= n; j++)
                a[i][j] = a[i + temp][(j + temp) % n];
        //�����½�
        for (i = temp + 1; i <= n; i++)
            for (j = temp + 1; j <= n; j++)
                a[i][j] = a[i - temp][j - temp];
    }
}
 
int main()
{
    int a[N+1][N+1];
    int temp = N;
    table(a, N, temp);

    //�����ͷ
    cout << "ѡ��" << "\t";
    for (int i = 1; i <= N - 1; i++)
    {
        cout << "��" << i << "��" << "\t";
    }
    cout << endl;

    //������̱�
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << a[i][j] << "       ";
        }
        cout << endl << endl;
    }

    return 0;
}