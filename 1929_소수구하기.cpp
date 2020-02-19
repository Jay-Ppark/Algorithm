#include<iostream>
using namespace std;
bool primenum[1000001];
int main(void)
{
	int start;
	int end;
	cin >> start >> end;
	for (int i = 2; i <= end; i++)
	{
		primenum[i] = true;
	}
	for (int i = 2; (i*i) <= 1000000; i++)
	{
		if (primenum[i])
		{
			for (int j = (i * i); j <= 1000000; j = j + i)
			{
				primenum[j] = false;
			}
		}
	}
	for (int i = start; i <= end; i++)
	{
		if (primenum[i])
		{
			cout << i << '\n';
		}
	}
	return 0;
}