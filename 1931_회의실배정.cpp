#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> conference;
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int startT;
		int endT;
		cin >> startT >> endT;
		conference.push_back({endT,startT });
	}
	int maxconfcnt = 1;
	sort(conference.begin(), conference.end());
	int firstendtime = conference[0].first;
	for (int i = 1; i < N; i++)
	{
		int nextstarttime = conference[i].second;
		if (nextstarttime >= firstendtime)
		{
			firstendtime = conference[i].first;
			maxconfcnt++;
		}
	}
	cout << maxconfcnt;
	return 0;
}