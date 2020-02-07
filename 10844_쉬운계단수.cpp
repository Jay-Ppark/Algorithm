#include<iostream>
using namespace std;
long long int dp[10][101];
int main(void)
{
	int N;
	int sum = 0;
	cin >> N;
	for (int i = 0; i <= 9; i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 9)
			{
				dp[9][i] = dp[8][i - 1] % 1000000000;
			}
			else if (j == 0)
			{
				dp[0][i] = dp[1][i - 1] % 1000000000;
			}
			else
			{
				dp[j][i] = (dp[j + 1][i - 1] + dp[j - 1][i - 1]) % 1000000000;
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		sum = (sum + dp[i][N]) % 1000000000;
	}
	cout << sum;
	return 0;
}