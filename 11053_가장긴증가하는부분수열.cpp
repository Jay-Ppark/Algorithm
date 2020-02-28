#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int max = dp[1];
	for (int i = 2; i <= N; i++)
	{
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	cout << max;
	return 0;
}