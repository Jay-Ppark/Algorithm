#include<iostream>
#include<deque>
using namespace std;
bool primeNum[1000001];
deque <int> prime;
void findPirmeNum()
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (!primeNum[i])
		{
			if (i != 2)
			{
				prime.push_back(i);
			}
			for (int j = i + i; j <= 1000000; j=j+i)
			{
				primeNum[j] = true;
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	findPirmeNum();
	int n;
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else
		{
			int cnt = 0;
			while (true)
			{
				int a = prime.at(cnt);
				if (!primeNum[n - a])
				{
					cout << n << " = " << a << " + " << n - a << '\n';
					break;
				}
				cnt++;
			}
		}
	}
	return 0;
}