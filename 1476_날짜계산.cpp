#include<iostream>
using namespace std;
int main(void)
{
	int E;
	int S;
	int M;
	int day = 1;
	cin >> E >> S >> M;
	while (true)
	{
		int tmpE = day - E;
		int tmpS = day - S;
		int tmpM = day - M;
		if (tmpE % 15 == 0 && tmpS % 28 == 0 && tmpM % 19 == 0)
		{
			break;
		}
		day++;
	}
	cout << day;
	return 0;
}