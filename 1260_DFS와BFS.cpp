#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector <int> edgeArr[1001];
bool visitNode[1001];
void Dfs(int n)
{
	if (visitNode[n])
	{
		return;
	}
	visitNode[n] = true;
	cout << n << " ";
	for (int i = 0; i < edgeArr[n].size(); i++)
	{
		Dfs(edgeArr[n][i]);
	}
}
void InitvisitNode(int n)
{
	for (int i = 1; i <= n; i++)
	{
		visitNode[i] = false;
	}
}
void Bfs(int n)
{
	queue<int> q;
	q.push(n);
	visitNode[n] = true;
	while (!q.empty())
	{
		int qtop = q.front();
		q.pop();
		cout << qtop << " ";
		for (int i = 0; i < edgeArr[qtop].size(); i++)
		{
			if (!visitNode[edgeArr[qtop][i]])
			{
				q.push(edgeArr[qtop][i]);
				visitNode[edgeArr[qtop][i]] = true;
			}
		}
	}
}
int main(void)
{
	int nodecnt;
	int edgecnt;
	int startV;
	cin >> nodecnt >> edgecnt >> startV;
	for (int i = 0; i < edgecnt; i++)
	{
		int startNode;
		int endNode;
		cin >> startNode >> endNode;
		edgeArr[startNode].push_back(endNode);
		edgeArr[endNode].push_back(startNode);
	}
	for (int i = 1; i <= nodecnt; i++)
	{
		sort(edgeArr[i].begin(), edgeArr[i].end());
	}
	Dfs(startV);
	InitvisitNode(nodecnt);
	cout << '\n';
	Bfs(startV);
	return 0;
}