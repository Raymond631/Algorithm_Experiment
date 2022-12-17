#include<iostream>
#include<vector>
using namespace std;

int n;//�����Ȼ��
vector<bool> isSelected; 
vector<int> result;

void backtrack(int m)
{
	if (m > n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << result[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!isSelected[i])
			{
				isSelected[i] = true;
				result.push_back(i);

				backtrack(m + 1); 

				result.pop_back();
				isSelected[i] = false;
			}
		}
	}
}

int main()
{
	cout << "�����������Ȼ����";
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		isSelected.push_back(false);
	}

	backtrack(1);

	return 0;
}