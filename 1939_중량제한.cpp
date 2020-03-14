#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool visited[100001];
int starte;
int ende;
vector<pair<int, int>> vb[100001];
void Init()
{
	for (int i = 0; i <= 100000; i++)
	{
		visited[i] = false;
	}
}
bool BFS(int w)
{
	visited[starte] = true;
	queue<int> q;
	q.push(starte);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == ende)
		{
			return true;
		}
		for (int i = 0; i < vb[cur].size(); i++)
		{
			int nexta = vb[cur][i].first;
			int nextw = vb[cur][i].second;
			if (!visited[nexta] && w <= nextw)
			{
				visited[nexta] = true;
				q.push(nexta);
			}
		}
	}
	return false;
}
int main(void)
{
	int N;
	int M;
	cin >> N >> M;
	int maxw = 0;
	for (int i = 0; i < M; i++)
	{
		int tmps;
		int tmpe;
		int tmpw;
		cin >> tmps >> tmpe >> tmpw;
		vb[tmps].push_back({ tmpe,tmpw });
		vb[tmpe].push_back({ tmps,tmpw });
		if (tmpw > maxw)
		{
			maxw = tmpw;
		}
	}
	cin >> starte >> ende;
	for (int i = 1; i <= N; i++)
	{
		sort(vb[i].begin(), vb[i].end());
	}
	int loww = 0;
	int highw = maxw;
	while (loww <= highw)
	{
		int midw = (loww + highw) / 2;
		if (BFS(midw))
		{
			loww = midw + 1;
		}
		else
		{
			highw = midw - 1;
		}
		Init();
	}
	cout << highw;
	/*
	for (int i = 0; i < vb.size(); i++)
	{
		cout << vb[i].first.first << " " << vb[i].first.second << '\n';
	}
	*/
	return 0;
}