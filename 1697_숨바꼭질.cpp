#include<iostream>
#include<queue>
using namespace std;
bool visited[100001];
int cnt;
int BFS(int startnode, int endnode)
{
	queue<int> cal;
	cal.push(startnode);
	visited[startnode] = true;
	while (true)
	{
		int calSize = cal.size();
		for (int i = 0; i < calSize; i++)
		{
			int ctop = cal.front();
			cal.pop();
			if (ctop == endnode)
			{
				return cnt;
			}
			if (ctop - 1 >= 0 && !visited[ctop - 1])
			{
				cal.push(ctop - 1);
				visited[ctop - 1] = true;
			}
			if (ctop + 1 <= 100000 && !visited[ctop + 1])
			{
				cal.push(ctop + 1);
				visited[ctop + 1] = true;
			}
			if (ctop * 2 <= 100000 && !visited[ctop * 2])
			{
				cal.push(ctop * 2);
				visited[ctop * 2] = true;
			}
		}
		cnt++;
	}
}
int main(void)
{
	int subin;
	int subinBro;
	cin >> subin >> subinBro;
	cout << BFS(subin,subinBro);
	return 0;
}