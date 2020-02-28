#include<iostream>
#include<queue>
using namespace std;
bool mazemap[100][100];
int cnt = 1;
int BFS(int y,int x)
{
	queue<int> mapY;
	queue<int> mapX;
	mapY.push(0);
	mapX.push(0);
	mazemap[0][0] = false;
	while (true)
	{
		int qSize = mapX.size();
		for (int i = 0; i < qSize; i++)
		{
			int mapYfront = mapY.front();
			int mapXfront = mapX.front();
			mapY.pop();
			mapX.pop();
			if (mapXfront + 1 == x && mapYfront + 1 == y)
			{
				return cnt;
			}
			if (mapXfront - 1 >= 0 && mazemap[mapYfront][mapXfront - 1])
			{
				mapY.push(mapYfront);
				mapX.push(mapXfront - 1);
				mazemap[mapYfront][mapXfront - 1] = false;
			}
			if (mapXfront + 1 < x && mazemap[mapYfront][mapXfront + 1])
			{
				mapY.push(mapYfront);
				mapX.push(mapXfront + 1);
				mazemap[mapYfront][mapXfront + 1] = false;
			}
			if (mapYfront - 1 >= 0 && mazemap[mapYfront - 1][mapXfront])
			{
				mapY.push(mapYfront - 1);
				mapX.push(mapXfront);
				mazemap[mapYfront - 1][mapXfront] = false;
			}
			if (mapYfront + 1 < y && mazemap[mapYfront + 1][mapXfront])
			{
				mapY.push(mapYfront + 1);
				mapX.push(mapXfront);
				mazemap[mapYfront + 1][mapXfront] = false;
			}
		}
		cnt++;
	}
}
int main(void)
{
	int N;
	int M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			scanf_s("%1d", &temp);
			if (temp == 1)
			{
				mazemap[i][j] = true;
			}
		}
	}
	cout << BFS(N, M);
	return 0;
}