#include<iostream>
#include<cmath>
using namespace std;
int answer = 0;
void findAnswer(int N, int h, int w)
{
	if (h >= pow(2,N - 1) && w >= pow(2, N - 1))
	{
		answer = answer + pow(2,(2 * N)) - pow(2,(2 * (N - 1)));
		h = h - pow(2,N - 1);
		w = w - pow(2,N - 1);
		N = N - 1;
		if (h == 1 && w == 1)
		{
			answer = answer + 3;
		}
		else
		{
			findAnswer(N, h, w);
		}
	}
	else if (h >= pow(2, N - 1))
	{
		answer = answer + pow(2,(2 * N) - 1);
		h = h - pow(2,N - 1);
		N = N - 1;
		if (h == 1 && w == 0)
		{
			answer = answer + 2;
		}
		else
		{
			findAnswer(N, h, w);
		}
	}
	else if (w >= pow(2, N - 1))
	{
		answer = answer + pow(2,(2 * N) - 2);
		w = w - pow(2,N - 1);
		N = N - 1;
		if (h == 0 && w == 1)
		{
			answer = answer + 1;
		}
		else
		{
			findAnswer(N, h, w);
		}
	}
	else
	{
		if (w == 0 && h == 0)
		{
			answer = answer;
		}
		else
		{
			N = N - 1;
			findAnswer(N, h, w);
		}
	}
}
int main(void)
{
	int num;
	int r;
	int c;
	cin >> num >> r >> c;
	findAnswer(num, r, c);
	cout << answer;
	return 0;
}