#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int height;
int width;
bool visit[100][100];
int wholemap[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<int> reccntarr;
int tmprec;
void DFS(int h, int w)
{
	visit[h][w] = true;
	tmprec++;
	for (int i = 0; i < 4; i++)
	{
		int tmpY = h + dy[i];
		int tmpX = w + dx[i];
		if (tmpY >= 0 && tmpY < height && tmpX >= 0 && tmpX < width)
		{
			if (wholemap[tmpY][tmpX] != 1 && !visit[tmpY][tmpX])
			{
				DFS(tmpY, tmpX);
			}
		}
	}
}
int main(void)
{
	int reccnt;
	cin >> height >> width >> reccnt;
	while (reccnt > 0)
	{
		int lx;
		int ly;
		int rx;
		int ry;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; i++)
		{
			for (int j = lx; j < rx; j++)
			{
				wholemap[i][j] = 1;
			}
		}
		reccnt--;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (!visit[i][j] && wholemap[i][j]==0)
			{
				DFS(i, j);
				reccntarr.push_back(tmprec);
				tmprec = 0;
			}
		}
	}
	sort(reccntarr.begin(), reccntarr.end());
	cout << reccntarr.size() << '\n';
	for (int i = 0; i < reccntarr.size(); i++)
	{
		cout << reccntarr[i] << " ";
	}
	/*
	for (int i = height-1; i >=0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			cout << wholemap[i][j];
		}
		cout << '\n';
	}
	*/
	return 0;
}