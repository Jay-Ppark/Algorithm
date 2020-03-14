#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
priority_queue<int,vector<int>,greater<int>> plusnum;
priority_queue<int,vector<int>, less<int>> minusnum;
int main(void)
{
	int arrcnt = 0;
	int pluscnt = 0;
	int minuscnt = 0;
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int command;
		cin >> command;
		if (command == 0)
		{
			if (arrcnt == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				if (pluscnt != 0 && minuscnt != 0)
				{
					if (plusnum.top() < abs(minusnum.top()))
					{
						cout << plusnum.top() << '\n';
						plusnum.pop();
						pluscnt--;
						arrcnt--;
					}
					else if(plusnum.top() > abs(minusnum.top()))
					{
						cout << minusnum.top() << '\n';
						minusnum.pop();
						minuscnt--;
						arrcnt--;
					}
					else
					{
						cout << minusnum.top() << '\n';
						minusnum.pop();
						minuscnt--;
						arrcnt--;
					}
				}
				else if (pluscnt == 0)
				{
					cout << minusnum.top() << '\n';
					minusnum.pop();
					minuscnt--;
					arrcnt--;
				}
				else if (minuscnt == 0)
				{
					cout << plusnum.top() << '\n';
					plusnum.pop();
					pluscnt--;
					arrcnt--;
				}
			}
		}
		else
		{
			if (command > 0)
			{
				plusnum.push(command);
				pluscnt++;
				arrcnt++;
			}
			else
			{
				minusnum.push(command);
				minuscnt++;
				arrcnt++;
			}
		}
	}
	return 0;
}