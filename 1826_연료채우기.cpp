#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int, int>> v;
int main(void)
{
	//멈추는 횟수를 최소화  1가는데 1소비
	int stationnum;
	cin >> stationnum;
	for (int i = 0; i < stationnum; i++)
	{
		int tmpa;
		int tmpb;
		cin >> tmpa >> tmpb;
		v.push_back({ tmpa,tmpb });
	}
	sort(v.begin(), v.end());
	int distance;
	int oil;
	cin >> distance >> oil;
	int gasstop = 0;
	priority_queue<int> pq;
	int index = 0;
	while (true)
	{
		if (oil >= distance)
		{
			break;
		}
		while (index < stationnum && v[index].first <= oil)
		{
			pq.push(v[index].second);
			index++;
		}
		if (pq.empty())
		{
			break;
		}
		gasstop++;
		oil = oil + pq.top();
		pq.pop();
	}
	if (oil < distance)
	{
		cout << -1;
	}
	else
	{
		cout << gasstop;
	}
	return 0;
}