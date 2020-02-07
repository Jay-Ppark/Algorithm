#include<iostream>
using namespace std;
int main(void)
{
	int numseq[3] = { 0,0,0 };
	int num;
	cin >> num;
	int cnt = 0;
	if (num < 100)
	{
		cout << num << endl;
	}
	else if (num == 1000)
	{
		cout << 144 << endl;
	}
	else
	{
		cnt = 99;
		for (int i = 100; i <= num; i++)
		{
			numseq[0] = i % 10;
			numseq[2] = i / 100;
			numseq[1] = (i - (numseq[2] * 100) - numseq[0]) / 10;
			if ((numseq[0] - numseq[1]) == (numseq[1] - numseq[2]))
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}