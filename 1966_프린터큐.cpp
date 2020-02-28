#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int main(void)
{
	int testcase;
	cin >> testcase;
	queue<pair<int,int>> q;
	priority_queue<int> qimp;
	for (int i = 0; i < testcase; i++)
	{
		int cnt = 0;
		int filenum;
		int fileat;
		cin >> filenum >> fileat;
		for (int j = 0; j < filenum; j++)
		{
			int temp;
			cin >> temp;
			q.push(make_pair(j, temp));
			qimp.push(temp);
		}
		while (!q.empty())
		{
			int index;
			int findfile;
			if (qimp.top() != q.front().second)
			{
				index = q.front().first;
				findfile = q.front().second;
				q.pop();
				q.push(make_pair(index, findfile));
			}
			else
			{
				qimp.pop();
				index = q.front().first;
				findfile = q.front().second;
				q.pop();
				cnt++;
				if (index == fileat)
				{
					cout << cnt << '\n';
				}
			}
		}
	}
}