#include<iostream>
using namespace std;
int arr[20000001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int M = 0;
	int temp = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[temp + 10000000]++;
	}
	cin >> M;
	for (int j = 0; j < M; j++)
	{
		cin >> temp;
		cout << arr[temp + 10000000] << " ";
	}
	return 0;
}