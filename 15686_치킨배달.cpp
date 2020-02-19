#include<iostream>
#include<vector>
using namespace std;
int city[50][50];
vector<int> housex;
vector<int> housey;
vector<int> chickenx;
vector<int> chickeny;
bool visitedchicken[13];
int N;
int M;
int citymin = 10000;
int housecnt = 0;
int chickencnt = 0;
void findMin(int cnt,int start)
{
	if (cnt == M)
	{
		vector<int> checkchickenSum;
		for (int i = 0; i < housecnt; i++)
		{
			checkchickenSum.push_back(10000);
		}
		int result = 0;
		for (int i = 0; i < chickencnt; i++)
		{
			if (visitedchicken[i])
			{
				for (int j = 0; j < housecnt; j++)
				{
					if (checkchickenSum[j] > (abs(housex[j] - chickenx[i]) + abs(housey[j] - chickeny[i])))
					{
						checkchickenSum[j] = abs(housex[j] - chickenx[i]) + abs(housey[j] - chickeny[i]);
					}
				}
			}
		}
		for (int i = 0; i < housecnt; i++)
		{
			result = result + checkchickenSum[i];
		}
		if (result < citymin)
		{
			citymin = result;
		}
		checkchickenSum.clear();
		return;
	}
	for (int i = start; i < chickencnt; i++)
	{
		if (!visitedchicken[i])
		{
			visitedchicken[i] = true;
			findMin(cnt + 1, i + 1);
			visitedchicken[i] = false;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
			{
				housex.push_back(j);
				housey.push_back(i);
				housecnt++;
			}
			else if (city[i][j] == 2)
			{
				chickenx.push_back(j);
				chickeny.push_back(i);
				chickencnt++;

			}
		}
	}
	findMin(0, 0);
	cout << citymin;
	return 0;
}