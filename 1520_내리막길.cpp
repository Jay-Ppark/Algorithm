#include<iostream>
using namespace std;
int arr[500][500];
long long int dp[500][500];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int M;
int N;
int DFS(int y, int x)
{
	if (y == M - 1 && x == N - 1)
	{
		return 1;
	}
	if (dp[y][x] != -1)
	{
		return dp[y][x];
	}
	dp[y][x] = 0;
	for (int k = 0; k < 4; k++)
	{
		int tmpy = y + dy[k];
		int tmpx = x + dx[k];
		if (tmpy < M && tmpx < N && tmpy >= 0 && tmpx >= 0)
		{
			if (arr[y][x] > arr[tmpy][tmpx])
			{
				dp[y][x] = DFS(tmpy, tmpx) + dp[y][x];
			}
		}
	}
	return dp[y][x];
}
int main(void)
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}


	//cout << '\n';
	cout << DFS(0, 0);
	return 0;
}