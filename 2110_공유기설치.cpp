#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> house;
int housenum;
int havenet(int n)
{
	int cnt = 0;
	long long int start = house[0];
	for (int i = 1; i < housenum; i++)
	{
		if (house[i] - start >= n)
		{
			cnt++;
			start = house[i];
		}
	}
	return cnt + 1;
}
int main(void)
{
	long long int result = 0;
	int netnum;
	cin >> housenum >> netnum;
	long long int max = 0;
	for (int i = 1; i <= housenum; i++)
	{
		long long int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());
	long long int lefth = 1;
	long long int righth = house[housenum - 1] - house[0];
	while (lefth <= righth)
	{
		long long int midh = (righth + lefth) / 2;
		long long int tmp = havenet(midh);
		if (tmp >= netnum)
		{
			result = midh;
			lefth = midh + 1;
		}
		else
		{
			righth = midh - 1;
		}
	}
	cout << result;
	return 0;
}