#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>;
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
	int result = dp[sslen][fslen];
	cout << result << '\n';
	int cnt = 0;
	stack<char> s;
	while (cnt != result)
	{
		if (dp[sslen][fslen] == dp[sslen][fslen - 1])
		{
			fslen--;
		}
		else if (dp[sslen][fslen] == dp[sslen - 1][fslen])
		{
			sslen--;
		}
		else if (dp[sslen][fslen] - 1 == dp[sslen - 1][fslen - 1])
		{
			sslen--;
			fslen--;
			cnt++;
			s.push(fs[fslen]);
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}