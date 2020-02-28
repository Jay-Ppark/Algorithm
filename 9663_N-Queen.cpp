#include<iostream>
using namespace std;
int line[14];
int result;
int queen;
int N;
bool checkQueen(int y)
{
	for (int i = 0; i < y; i++)
	{
		if (line[y] == line[i] || y - i == abs(line[y] - line[i]))
		{
			return false;
		}
	}
	return true;
}
void findAnswer(int y)
{
	if (y == N)
	{
		result++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		line[y] = i;
		if (checkQueen(y))
		{
			findAnswer(y + 1);
		}
	}
}
int main(void)
{
	cin >> N;
	findAnswer(0);
	cout << result;
	return 0;
}