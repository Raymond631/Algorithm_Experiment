#include<iostream>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
	//������������
	int length = right - left + 1;
	int* temp = new int[length];

	int i = left;//������һ��
	int j = mid + 1;//������һ��
	int k = 0;
	while (i <= mid && j <= right)//3��ѭ����Ҫ�Ⱥ�
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

	//��temp���ź���������滻array�е�ԭʼ����
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

	//���������
	srand(time(0));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % length;
	}

	cout << "����ǰ��" << endl;
	print(array, 100);
	mergeSort(array, 0, length - 1);	//�鲢����
	cout << "�����" << endl;
	print(array, 100);

	//���������ȷ��
	if (isSort(array,length))
		cout << "����ɹ�!" << endl;
	else
		cout << "���棬��������" << endl;

	return 0;
}