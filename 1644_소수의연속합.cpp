#include<iostream>
#include<deque>
using namespace std;
bool primeNum[4000001];
int N;
deque<int> result;
void findPrimeNum()
{
	for (int i = 2; i <= N; i++)
	{
		if (!primeNum[i])
		{
			result.push_back(i);
			for (int j = i + i; j <= N; j = j + i)//long long j=i*i
			{
				primeNum[j] = true;
			}
		}
	}
}
int main(void)
{
	cin >> N;
	findPrimeNum();
	int cnt = 0;
	int answer = 0;
	int result_size = result.size();
	while (result_size != 0)
	{
		int temp = 0;
		for (int i = 0; i < result_size; i++)
		{
			temp = temp + result[i];
			if (temp == N)
			{
				answer++;
				break;
			}
			else if (temp > N)
			{
				break;
			}
		}
		result_size--;
		result.pop_front();
	}
	cout << answer;
	return 0;
}