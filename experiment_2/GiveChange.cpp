#include<iostream>
using namespace std;

void giveChange(int n, int a[])
{
	while (n >= 25)
	{
		a[0]++;
		n = n - 25;
	}
	while (n >= 10)
	{
		a[1]++;
		n = n - 10;
	}
	while (n >= 5)
	{
		a[2]++;
		n = n - 5;
	}
	a[3] = n;
}

int main()
{
	cout << "�����������ܽ��(��)��";
	int n;
	cin >> n;

	int a[4] = { 0,0,0,0 };
	giveChange(n, a);
	cout << a[0] << "��2��5�ֵ�Ӳ��" << endl;
	cout << a[1] << "��1�ǵ�Ӳ��" << endl;
	cout << a[2] << "��5�ֵ�Ӳ��" << endl;
	cout << a[3] << "��1�ֵ�Ӳ��" << endl;

	return 0;
}