#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (v.empty())
		{
			v.push_back(tmp);
			cnt++;
		}
		else
		{
			if (tmp > v.back())
			{
				v.push_back(tmp);
				cnt++;
			}
			else
			{
				auto it = lower_bound(v.begin(), v.end(), tmp);
				*it = tmp;
			}
		}
	}
	cout << cnt;
	return 0;
}