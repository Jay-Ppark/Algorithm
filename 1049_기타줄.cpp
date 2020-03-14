#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
vector<int> result;
int main(void)
{
	int N;
	int M;
	cin >> N >> M;
	int minsix = 1000;
	int minone = 1000;
	for (int i = 0; i < M; i++)
	{
		int tmpsix;
		int tmpone;
		cin >> tmpsix >> tmpone;
		v.push_back({ tmpsix,tmpone });
		if (tmpsix < minsix)
		{
			minsix = tmpsix;
		}
		if (tmpone < minone)
		{
			minone = tmpone;
		}
	}
	if (N % 6 == 0)
	{
		result.push_back(N / 6 * minsix);
		result.push_back(N * minone);
	}
	else
	{
		result.push_back(((N / 6) + 1) * minsix);
		result.push_back(N * minone);
		result.push_back((N / 6) * minsix + (N % 6) * minone);
	}
	sort(result.begin(), result.end());
	cout << result[0];
	return 0;
}