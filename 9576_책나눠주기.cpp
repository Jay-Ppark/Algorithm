#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool checked[1001];
vector<pair<int, int>> v;
void init()
{
	for (int i = 0; i <= 1000; i++)
	{
		checked[i] = false;
	}
}
int main(void)
{
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		int result = 0;
		int N;
		int M;
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			int tmps;
			int tmpe;
			cin >> tmps >> tmpe;
			v.push_back({ tmpe,tmps });
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = v[i].second; j <= v[i].first; j++)
			{
				if (!checked[j])
				{
					checked[j] = true;
					result++;
					break;
				}
			}
		}
		cout << result << '\n';
		v.clear();
		init();
		testcase--;
	}
	return 0;
}