#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> rope;
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		rope.push_back(temp);

	}
	sort(rope.begin(), rope.end());
	int maxweight = rope[N - 1];
	int cnt = 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (maxweight <= rope[i] * cnt)
		{
			maxweight = rope[i] * cnt;
		}
		cnt++;
	}
	cout << maxweight;
	return 0;
}