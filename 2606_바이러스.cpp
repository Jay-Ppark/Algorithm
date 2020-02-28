#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool visitedCom[101];
vector <int> NetArr[101];
int cnt = 0;
void BFS()
{
	queue<int> q;
	q.push(1);
	visitedCom[1] = true;
	while (!q.empty())
	{
		int qFront = q.front();
		q.pop();
		for (int i = 0; i < NetArr[qFront].size(); i++)
		{
			if (!visitedCom[NetArr[qFront][i]])
			{
				q.push(NetArr[qFront][i]);
				visitedCom[NetArr[qFront][i]] = true;
				cnt++;
			}
		}
	}
}
int main(void)
{
	int comNum;
	int netNum;
	cin >> comNum >> netNum;
	for (int i = 0; i < netNum; i++)
	{
		int startCom;
		int endCom;
		cin >> startCom >> endCom;
		NetArr[startCom].push_back(endCom);
		NetArr[endCom].push_back(startCom);
	}
	for (int i = 1; i <= comNum; i++)
	{
		sort(NetArr[i].begin(), NetArr[i].end());
	}
	BFS();
	cout << cnt;
	return 0;
}