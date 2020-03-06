#include<iostream>
#include<vector>
using namespace std;
int cheeze[100][100];
bool visited[100][100];
int height;
int width;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int tmpleftcheeze;
vector<pair<int, int>> meltcheezedot;
void findouter(int h,int w)
{
	for (int i = 0; i < 4; i++)
	{
		int tmpY = h + dy[i];
		int tmpX = w + dx[i];
		if (tmpY >= 0 && tmpY < height && tmpX >= 0 && tmpX < width)
		{
			if (cheeze[tmpY][tmpX] != 1 && !visited[tmpY][tmpX])
			{
				cheeze[tmpY][tmpX] = -1;
				visited[tmpY][tmpX] = true;
				findouter(tmpY, tmpX);
			}
		}
	}
}
void meltcheeze(int h, int w)
{
	if (cheeze[h][w] == 1)
	{
		if (cheeze[h - 1][w] == -1 || cheeze[h + 1][w] == -1 || cheeze[h][w - 1] == -1 || cheeze[h][w + 1] == -1)
		{
			tmpleftcheeze++;
			meltcheezedot.push_back({ h,w });
		}
	}
}
int main(void)
{
	cin >> height >> width;
	int cheezecnt = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> cheeze[i][j];
			if (cheeze[i][j] == 1)
			{
				cheezecnt++;
			}
		}
	}
	findouter(0, 0);
	int hour = 0;
	while (cheezecnt > 0)
	{
		hour++;
		tmpleftcheeze = 0;
		for (int i = 1; i < height-1; i++)
		{
			for (int j = 1; j < width-1; j++)
			{
				meltcheeze(i, j);
			}
		}
		cheezecnt = cheezecnt - tmpleftcheeze;
		while (!meltcheezedot.empty())
		{
			int tmpY = meltcheezedot.back().first;
			int tmpX = meltcheezedot.back().second;
			meltcheezedot.pop_back();
			cheeze[tmpY][tmpX] = -1;
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if(!visited[i][j]&&cheeze[i][j]==-1)
				{
					findouter(i, j);
				}
			}
		}
		
	}
	cout << hour << '\n' << tmpleftcheeze;
	
	/*
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << cheeze[i][j];
		}
		cout << '\n';
	}
	*/
	return 0;
}