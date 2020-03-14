#include<iostream>
using namespace std;
int arr[100001];
int main(void)
{
	int N;
	long long int M;
	long long int tmpmax = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		if (arr[i] > tmpmax)
		{
			tmpmax = arr[i];
		}
	}
	long long int lowt = 1;
	long long int hight = tmpmax * M;
	long long int result = 0;
	while (lowt <= hight)
	{
		long long int midt = (lowt + hight) / 2;
		long long int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			cnt = cnt + midt / arr[i];
		}
		if (cnt >= M)
		{
			hight = midt - 1;
		}
		else
		{
			lowt = midt + 1;
			if (result < lowt)
			{
				result = lowt;
			}
		}
	}
	cout << result;
	return 0;
}