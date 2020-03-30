#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int dp[1001][1001];
int main(void)
{
	string fs;
	string ss;
	cin >> fs >> ss;
	int fslen = fs.length();
	int sslen = ss.length();
	for (int i = 1; i <= sslen; i++)
	{
		for (int j = 1; j <= fslen; j++)
		{
			if (ss[i - 1] == fs[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[sslen][fslen];
	return 0;
}