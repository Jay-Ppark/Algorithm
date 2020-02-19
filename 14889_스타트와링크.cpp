#include<iostream>
using namespace std;
int team[20][20];
bool haveteam[20];
int N;
int result = 1000000;
void findMin(int cnt, int next)
{
	if (cnt == N / 2)
	{
		int trueteam = 0;
		int falseteam = 0;
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (haveteam[i])
				{
					if (haveteam[j])
					{
						trueteam = trueteam + team[i][j] + team[j][i];
					}
				}
				else
				{
					if (!haveteam[j])
					{
						falseteam = falseteam + team[i][j] + team[j][i];
					}
				}
			}
		}
		if (result > abs(trueteam - falseteam))
		{
			result = abs(trueteam - falseteam);
		}
		return;
	}
	for (int i = next; i < N; i++)
	{
		if (!haveteam[i])
		{
			haveteam[i] = true;
			findMin(cnt + 1, i + 1);
			haveteam[i] = false;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> team[i][j];
		}
	}
	haveteam[0] = true;
	findMin(1, 0);
	cout << result;
	return 0;
}