#include<iostream>
#include<vector>
using namespace std;
bool primeNum[2000001];
vector <int> v;
void findPrimeNum()
{
	for (int i = 2; i <= 2000000; i++)
	{
		if (!primeNum[i])
		{
			v.push_back(i);
			for (int j = i + i; j <= 2000000; j = j + i)
			{
				primeNum[j] = true;
			}
		}
	}
}
int main(void)
{
	int testcase;
	cin >> testcase;
	findPrimeNum();
	for (int i = 0; i < testcase; i++)
	{
		long long int a;
		long long int b;
		cin >> a >> b;
		long long int sum = a + b;
		bool correct = true;
		if (sum < 4)
		{
			cout << "NO\n";
		}
		else
		{
			if ((sum % 2) == 0)
			{
				cout << "YES\n";
			}
			else
			{
				sum = sum - 2;
				for (int i = 0; i < v.size() && (long long)v[i] * v[i] <= sum; i++)
				{
					if (sum % v[i] == 0)
					{
						correct = false;
						break;
					}
				}
				if (correct)
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}