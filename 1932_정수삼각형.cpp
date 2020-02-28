#include<iostream>
#include<algorithm>
using namespace std;
int dp[501][501];
int arr[501][501];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] = arr[i][j] + dp[i - 1][j];
			}
			else if (j == i)
			{
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	int max = dp[n][1];
	for (int i = 2; i <= n; i++)
	{
		if (max < dp[n][i])
		{
			max = dp[n][i];
		}
	}
	cout << max;
	return 0;
}