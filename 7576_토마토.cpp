#include<iostream>
#include<queue>
using namespace std;
int tomato[1000][1000];
int M;
int N;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int main(void)
{
	cin >> M >> N;
	int ripetomato = 0;
	int tomatocnt = 0;
	queue<pair<int, int> > tomatoq;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] != -1)
			{
				tomatocnt++;
				if (tomato[i][j] == 1)
				{
					tomatoq.push({ i,j });
					ripetomato++;
				}
			}
		}
	}
	if (ripetomato == 0)
	{
		cout << -1;
	}
	else if (ripetomato == tomatocnt)
	{
		cout << 0;
	}
	else
	{
		int lefttomato = tomatocnt - ripetomato;
		int day = 0;
		while (!tomatoq.empty())
		{
			int tomatoqSize = tomatoq.size();
			for (int i = 0; i < tomatoqSize; i++)
			{
				int tomatoY = tomatoq.front().first;
				int tomatoX = tomatoq.front().second;
				tomatoq.pop();
				for (int j = 0; j < 4; j++)
				{
					int tempY = tomatoY + dy[j];
					int tempX = tomatoX + dx[j];
					if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M)
					{
						if (tomato[tempY][tempX] == 0)
						{
							tomatoq.push({ tempY,tempX });
							tomato[tempY][tempX] = 1;
							lefttomato--;
						}
					}
				}
			}
			day++;
		}
		if (lefttomato == 0)
		{
			cout << day - 1;
		}
		else
		{
			cout << -1;
		}
	}
	return 0;
}