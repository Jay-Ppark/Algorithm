#include<iostream>
#include<math.h>
using namespace std;
int N;
int arr[2][11];
bool used[11];
int answer = 100000000;
void findAns(int cnt, int start,int mul,int sum)
{
	if (cnt >= 1)
	{
		int temp = abs(mul - sum);
		if (temp < answer)
		{
			answer = temp;
		}
	}
	for (int i = start; i <= N; i++)
	{
		if (used[i] == false)
		{
			used[i] = true;
			findAns(cnt + 1, i, mul * arr[0][i], sum + arr[1][i]);
			used[i] = false;
		}
	}
}
int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[0][i] >> arr[1][i];
	}
	findAns(0, 1, 1, 0);
	cout << answer;
	return 0;
}