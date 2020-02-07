#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000];
int main(void)
{
	int N;
	cin >> N;
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}