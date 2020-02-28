#include<iostream>
#include<vector>
using namespace std;
int gamemap[9][9];
vector< vector<int> > maprow;
vector< vector<int> > mapline;
void checkMap(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << gamemap[i][j] << " ";
			}
			cout << '\n';
		}
		return;
	}
	int y = cnt / 9;
	int x = cnt % 9;
	if (gamemap[y][x] != 0)
	{
		checkMap(cnt + 1);
	}
	else
	{

	}
}
int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> gamemap[i][j];
			if (gamemap[i][j] == 0)
			{
				mapline[i].push_back(j);
				maprow[]
			}
		}
	}
}