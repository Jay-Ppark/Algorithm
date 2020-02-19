#include<iostream>
#include<vector>
using namespace std;
bool lotto[13];
vector <int> v;
int testcase = 1;
void makeSixnum(int cnt,int start)
{
	if (cnt == 6)
	{
		for (int i = 1; i <= testcase; i++)
		{
			if (lotto[i])
			{
				cout << v[i - 1] << " ";
			}
		}
		cout << '\n';
	}
	else
	{
		for (int i = start; i <= testcase; i++)
		{
			lotto[i] = true;
			makeSixnum(cnt+1, i+1);
			lotto[i] = false;
		}
	}
}
int main(void)
{
	while (testcase != 0)
	{
		cin >> testcase;
		for (int i = 1; i <= testcase; i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		makeSixnum(0, 1);
		v.clear();
		cout << '\n';
	}
	return 0;
}