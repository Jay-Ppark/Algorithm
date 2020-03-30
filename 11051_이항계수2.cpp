#include<iostream>
using namespace std;
int dp[1001][1001];
int main(void)
{
	int N;
	int K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
			}
			else if (j == i)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
			}
		}
	}
	cout << dp[N][K];
	return 0;
}