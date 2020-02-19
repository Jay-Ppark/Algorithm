#include<iostream>
using namespace std;
bool primenum[1001];
void findPrimeNum()
{
	primenum[1] = true;
	primenum[2] = false;
	for (int i = 3; i <= 1000; i=i+1)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				primenum[i] = true;
				break;
			}
		}
	}
}
int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	findPrimeNum();
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (!primenum[temp])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}