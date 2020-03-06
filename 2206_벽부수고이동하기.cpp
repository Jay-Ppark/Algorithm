#include<iostream>
#include<queue>
using namespace std;
bool wholemap[1000][1000];
int dp[1000][1000][2];
int N;
int M;
bool haveroute;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int rd;
int main(void)
{
	cin >> N >> M;
	queue<pair<pair<int, int>, int>> makeroute;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			scanf_s("%1d", &temp);
			if (temp == 1)
			{
				wholemap[i][j] = true;
			}
		}
	}
	dp[0][0][1] = 1;
	int result = 0;
	makeroute.push({ {0,0}, 1 });//1이면 아직 벽 안부순거
	while (!makeroute.empty())
	{
		int preY = makeroute.front().first.first;
		int preX = makeroute.front().first.second;
		int havedelete = makeroute.front().second;
		makeroute.pop();
		if (preY == N - 1 && preX == M - 1)
		{
			haveroute = true;
			rd = havedelete;
			break;
		}
		for (int j = 0; j < 4; j++)
		{
			int tempY = preY + dy[j];
			int tempX = preX + dx[j];
			if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M)
			{
				if (wholemap[tempY][tempX] == true && havedelete == 1 )
				{
					dp[tempY][tempX][0] = dp[preY][preX][1] + 1;
					makeroute.push({ {tempY,tempX},havedelete - 1 });
				}
				else if (wholemap[tempY][tempX] == false && dp[tempY][tempX][havedelete] == 0)
				{
					makeroute.push({ {tempY,tempX},havedelete });
					dp[tempY][tempX][havedelete] = dp[preY][preX][havedelete] + 1;
				}
			}
		}
	}
	if (haveroute)
	{
		cout << dp[N - 1][M - 1][rd];
	}
	else
	{
		cout << -1;
	}
	return 0;
}