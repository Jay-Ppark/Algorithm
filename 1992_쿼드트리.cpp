#include<iostream>
#include<string>
using namespace std;
int N;
bool arr[64][64];
void solve(int t,int tmpy,int tmpx)
{
	if (t == 1)
	{
		if (arr[tmpy][tmpx])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return;
	}
	bool Isblack = true;
	bool Iswhite = true;
	for (int i = tmpy; i < tmpy + t; i++)
	{
		for (int j = tmpx; j < tmpx + t; j++)
		{
			if (arr[i][j])
			{
				Iswhite = false;
			}
			else
			{
				Isblack = false;
			}
		}
	}
	if (Isblack)
	{
		cout << 1;
	}
	else if (Iswhite)
	{
		cout << 0;
	}
	else
	{
		cout << '(';
		solve(t / 2, tmpy, tmpx);
		solve(t / 2, tmpy, tmpx + t / 2);
		solve(t / 2, tmpy + t / 2, tmpx);
		solve(t / 2, tmpy + t / 2, tmpx + t / 2);
		cout << ')';
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++)
		{
			if (tmp[j] == '0')
			{
				arr[i][j] = false;
			}
			else
			{
				arr[i][j] = true;
			}
		}
	}
	solve(N, 0, 0);
	return 0;
}