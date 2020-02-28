#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][3];
int dp[1001][3];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}
	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
	return 0;
}