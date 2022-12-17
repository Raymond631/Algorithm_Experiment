#include<iostream>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
	//创建辅助数组
	int length = right - left + 1;
	int* temp = new int[length];

	int i = left;//左区第一个
	int j = mid + 1;//右区第一个
	int k = 0;
	while (i <= mid && j <= right)//3个循环都要等号
	{
		temp[k++] = array[i] <= array[j] ? array[i++] : array[j++];
	}
	while (i <= mid)
	{
		temp[k++] = array[i++];
	}
	while (j <= right)
	{
		temp[k++] = array[j++];
	}

	//用temp中排好序的数据替换array中的原始数据
	for (int i = 0; i < length; i++)
	{
		array[left + i] = temp[i];
	}
	delete[] temp;
}

void mergeSort(int array[], int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);

	merge(array, left, mid, right);
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
	mergeSort(array, 0, length - 1);	//归并排序
	cout << "排序后：" << endl;
	print(array, 100);

	//检查排序正确性
	if (isSort(array,length))
		cout << "排序成功!" << endl;
	else
		cout << "警告，排序有误！" << endl;

	return 0;
}