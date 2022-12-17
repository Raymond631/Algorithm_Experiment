#include<iostream>
using namespace std;

void quickSort(int array[], int low, int high)
{
	if (low >= high)
		return;
	int i = low;
	int j = high;
	int key = array[i];

	while (i < j)
	{
		while (i < j && array[j] >= key)
			j--;
		if (i < j)
			array[i++] = array[j];

		while (i < j && array[i] <= key)
			i++;
		if (i < j)
			array[j--] = array[i];
	}
	array[i] = key;

	quickSort(array, low, i - 1);
	quickSort(array, i + 1, high);
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if (i != 0 && i % 20 == 0)
			cout << endl;
	}
	cout << endl << "----------------------------------------------------------------" << endl;
}

bool isSort(int array[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int array[100];
	int length = sizeof(array) / sizeof(array[0]);

	//生成随机数
	srand(time(0));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % length;
	}

	cout << "排序前：" << endl;
	print(array, 100);
	quickSort(array, 0, length - 1);	//快速排序
	cout << "排序后：" << endl;
	print(array, 100);

	//检查排序正确性
	if (isSort(array, length))
		cout << "排序成功!" << endl;
	else
		cout << "警告，排序有误！" << endl;

	return 0;
}