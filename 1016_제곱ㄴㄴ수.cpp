#include<iostream>
#include<cmath>
using namespace std;
bool result[1000001];
int main(void)
{
	long long minnum;
	long long maxnum;
	cin >> minnum >> maxnum;

	for (long long i = 2; i * i <= maxnum; i++)
	{
		long long startnum = minnum / (i * i);
		if (startnum * i * i != minnum)
		{
			startnum++;
		}
		for (long long j = startnum; i * i * j <= maxnum; j++)
		{
			result[i * i * j - minnum] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < maxnum - minnum + 1; i++)
	{
		if (!result[i])
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}