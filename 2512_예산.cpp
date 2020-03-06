#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	vector<int> needmoney;
	int resultmoney = 0;
	int maxmoney = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		needmoney.push_back(tmp);
		if (maxmoney < tmp)
		{
			maxmoney = tmp;
		}
	}
	long long int moneysum;
	cin >> moneysum;
	int leftmoney = 0;
	int rightmoney = maxmoney;
	while (leftmoney <= rightmoney)
	{
		int midmoney = (leftmoney + rightmoney) / 2;
		long long int tmpmoneysum = 0;
		for (int i = 0; i < N; i++)
		{
			if (needmoney[i] > midmoney)
			{
				tmpmoneysum = tmpmoneysum + midmoney;
			}
			else
			{
				tmpmoneysum = tmpmoneysum + needmoney[i];
			}
		}
		if (tmpmoneysum > moneysum)
		{
			rightmoney = midmoney - 1;
		}
		else
		{
			if (resultmoney < midmoney)
			{
				resultmoney = midmoney;
			}
			leftmoney = midmoney + 1;
		}
	}
	cout << resultmoney;
	return 0;
}