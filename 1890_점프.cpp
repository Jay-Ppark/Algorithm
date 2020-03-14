#include<iostream>
#include<queue>
using namespace std;
int arr[100][100];
long long int dp[100][100];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] == 0 || (i==N-1&&j==N-1))
			{
				continue;
			}
			if (j + arr[i][j] < N)
			{
				dp[i][j + arr[i][j]] = dp[i][j + arr[i][j]] + dp[i][j];
			}
			if (i + arr[i][j] < N)
			{
				dp[i + arr[i][j]][j] = dp[i + arr[i][j]][j] + dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1];
	return 0;
}