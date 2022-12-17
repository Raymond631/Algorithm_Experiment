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
	cout << "请输入找零总金额(分)：";
	int n;
	cin >> n;

	int a[4] = { 0,0,0,0 };
	giveChange(n, a);
	cout << a[0] << "个2角5分的硬币" << endl;
	cout << a[1] << "个1角的硬币" << endl;
	cout << a[2] << "个5分的硬币" << endl;
	cout << a[3] << "个1分的硬币" << endl;

	return 0;
}