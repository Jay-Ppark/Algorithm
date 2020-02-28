#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool housemap[25][25];
vector<int> housecnt;
int cnt;
int N;
void DFS(int y,int x)
{
	if (y - 1 >= 0)
	{
		if (housemap[y - 1][x])
		{
			housemap[y - 1][x] = false;
			cnt++;
			DFS(y - 1, x);
		}
	}
	if (y + 1 < N)
	{
		if (housemap[y + 1][x])
		{
			housemap[y + 1][x] = false;
			cnt++;
			DFS(y + 1, x);
		}
	}
	if (x - 1 >= 0)
	{
		if (housemap[y][x - 1])
		{
			housemap[y][x - 1] = false;
			cnt++;
			DFS(y, x - 1);
		}
	}
	if (x + 1 < N)
	{
		if (housemap[y][x + 1])
		{
			housemap[y][x + 1] = false;
			cnt++;
			DFS(y, x + 1);
		}
	}
	return;
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf_s("%1d", &temp);
			if (temp == 1)
			{
				housemap[i][j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (housemap[i][j])
			{
				cnt = 1;
				housemap[i][j] = false;
				DFS(i,j);
				housecnt.push_back(cnt);
			}
		}
	}
	sort(housecnt.begin(), housecnt.end());
	cout << housecnt.size() << '\n';
	for (int i = 0; i < housecnt.size(); i++)
	{
		cout << housecnt[i] << '\n';
	}
	return 0;
}