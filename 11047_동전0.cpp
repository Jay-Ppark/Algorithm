#include<iostream>
using namespace std;
int coin[11];
int main(void)
{
	int N;
	int K;
	cin >> N >> K;
	int needcoin = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}
	while (K != 0)
	{
		if (K >= coin[N])
		{
			needcoin = needcoin + K / coin[N];
			K = K % coin[N];
		}
		N--;
	}
	cout << needcoin;
	return 0;
}