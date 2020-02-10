#include<iostream>
using namespace std;
int arr[2001];
int main(void)
{
	int N;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[temp + 1000]++;
	}
	for (int i = 0; i < 2001; i++)
	{
		if (arr[i] != 0)
		{
			cout << i-1000 << " ";
		}
	}
	return 0;
}