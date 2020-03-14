#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int, int>> jewelry;
vector<int> bag;
priority_queue<int> pq;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long int result = 0;
	int jnum;
	int bnum;
	cin >> jnum >> bnum;
	for (int i = 0; i < jnum; i++)
	{
		int tmpw;
		int tmpv;
		cin >> tmpw >> tmpv;
		jewelry.push_back({ tmpw,tmpv });
	}
	for (int i = 0; i < bnum; i++)
	{
		int tmpb;
		cin >> tmpb;
		bag.push_back(tmpb);
	}
	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());
	int tmpindex = 0;
	for (int i = 0; i < bnum; i++)
	{
		while (tmpindex < jnum && jewelry[tmpindex].first <= bag[i])
		{
			pq.push(jewelry[tmpindex].second);
			tmpindex++;
		}
		if (!pq.empty())
		{
			result = result + pq.top();
			pq.pop();
		}
	}
	cout << result;
	
	return 0;
}