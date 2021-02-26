#include <iostream>
using namespace std;
int main()
{
	int m;//строки 
	int n;//столбцы 
	cout << "Enter rows count" << endl;
	cin >> m;
	cout << "Enter columns count " << endl;
	cin >> n;
	if (n <= 1 || m <= 1)//проверка вводных данных
		cout << "incorrect value entered" << endl;
	int** a = new int* [m];//создание динамического двумерного массива 
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++)//заполение случайными числами
	{
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 20;
	}
	cout << "original array" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
	int max = a[0][0];
	for (int i = 0; i < m; i++)//Нахождение максимального элемента и кол-во
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == max)
				count++;
		}

	}
	//cout << "number of maximum matrix elements=" << count << endl;
	int* arr = new int[n];
	int sum1 = 0, sum2 = 0;
	if (count > 1)
	{
		for (int i = 0; i < n; i++)
		{
			int value1 = a[0][i];
			int value2 = a[m - 1][i];
			{
				while (a[0][i] != 0)
				{
					sum1 += a[0][i] % 10;
					a[0][i] /= 10;
				}
				while (a[m - 1][i] != 0)
				{
					sum2 += a[m - 1][i] % 10;
					a[m - 1][i] /= 10;
				}
			}
			arr[i] = sum1 + sum2;
			a[0][i] = value1;
			a[m - 1][i] = value2;
			sum1 = sum2 = 0;
		}
		bool isSwap = true;
		while (isSwap)
		{
			isSwap = false;
			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] > arr[i])
				{
					for (int j = 0; j < m; j++)
					{
						int temp = a[j][i];
						a[j][i] = a[j][i - 1];
						a[j][i - 1] = temp;
					}
					isSwap = true;
					int temp = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = temp;
				}
			}
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "at most one maximum element in a matrix" << endl;

	for (int i = 0;i<n; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	if (count > 1)
	{
		cout << "new array" << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
	}
	delete[]arr;
	for (int i = 0; i < m; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}
