#include<iostream>
using namespace std;
int time[16];
int pay[16];
int dp[16];
int N;
int main(void)
{
	cin >> N;
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> time[i] >> pay[i];
		dp[i] = pay[i];
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i - j >= time[j])
			{
				if (dp[i] < pay[i] + dp[j])
				{
					dp[i] = pay[i] + dp[j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (i + time[i] - 1 <= N)
		{
			if (max < dp[i])
			{
				max = dp[i];
			}
		}
	}
	cout << max;
	return 0;
}