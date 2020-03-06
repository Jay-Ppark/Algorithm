#include<iostream>
#include<queue>
using namespace std;
int tomato[100][100][100];
int M;
int N;
int H;
int dz[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1 ,0,0 };
int dx[6] = { 0,0,0,0,-1,1 };
int main(void)
{
	cin >> M >> N >> H;
	int ripetomato = 0;
	int tomatocnt = 0;
	queue<pair<pair<int, int>,int> > tomatoq;
	for (int s = 0; s < H; s++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> tomato[s][i][j];
				if (tomato[s][i][j] != -1)
				{
					tomatocnt++;
					if (tomato[s][i][j] == 1)
					{
						tomatoq.push({ { i,j },s });
						ripetomato++;
					}
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
				int tomatoZ = tomatoq.front().second;
				int tomatoY = tomatoq.front().first.first;
				int tomatoX = tomatoq.front().first.second;
				tomatoq.pop();
				for (int j = 0; j < 6; j++)
				{
					int tempZ = tomatoZ + dz[j];
					int tempY = tomatoY + dy[j];
					int tempX = tomatoX + dx[j];
					if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M && tempZ>=0 && tempZ<H)
					{
						if (tomato[tempZ][tempY][tempX] == 0)
						{
							tomatoq.push({{ tempY,tempX }, tempZ });
							tomato[tempZ][tempY][tempX] = 1;
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