#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int haveline;
	int needline;
	cin >> haveline >> needline;
	vector<long long> lines;
	long long int maxline = 0;
	long long int result = 0;
	for (int i = 0; i < haveline; i++)
	{
		int tmp;
		cin >> tmp;
		lines.push_back(tmp);
		if (maxline < tmp)
		{
			maxline = tmp;
		}
	}
	long long int leftline = 0;
	long long int rightline = maxline;
	while (leftline <= rightline)
	{
		long long int midline = (leftline + rightline) / 2;
		if (midline == 0)
		{
			midline = 1;
		}
		long long int tmplinecnt = 0;
		for (int i = 0; i < haveline; i++)
		{
			if (lines[i] >= midline)
			{
				tmplinecnt = tmplinecnt + lines[i] / midline;
			}
		}
		if (tmplinecnt >= needline)
		{
			if (result < midline)
			{
				result = midline;
			}
			leftline = midline + 1;
		}
		else
		{
			rightline = midline - 1;
		}
	}
	cout << result;
	return 0;
}