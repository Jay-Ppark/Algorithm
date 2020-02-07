#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int arr[10001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		while (arr[i] != 0)
		{
			cout << i << '\n';
			arr[i]--;
		}
	}
	return 0;
}