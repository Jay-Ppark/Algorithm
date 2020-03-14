#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int, int>> station;
bool visited[1000];
int stationnum;
int stopnum;
void haveroute(int tmp)
{
	for (int i = 0; i < stationnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;

		}
		visited[i] = false;
	}
}
int main(void)
{
	int result = 10000;
	cin >> stationnum >> stopnum;
	for (int i = 0; i < stationnum; i++)
	{
		int tmpx;
		int tmpy;
		cin >> tmpx >> tmpy;
		station.push_back({ tmpx,tmpy });
	}

	return 0;
}