#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main(void)
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		bool haveerror = false;
		int Rcnt = 1;
		string command;
		cin >> command;
		int arrsize;
		cin >> arrsize;
		string arr;
		cin >> arr;
		deque<int> intarr;
		int temp = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] != '[' && arr[j] != ']')
			{
				int tempsize = 0;
				if (arr[j] == ',')
				{
					intarr.push_back(temp);
					temp = 0;
					tempsize = 0;
				}
				else
				{
					if (temp == 0)
					{
						temp = arr[j] - '0';
						tempsize = 1;
					}
					else
					{
						if (tempsize == 3)
						{
							temp = 100;
						}
						else
						{
							temp = temp * 10 + (arr[j] - '0');
							tempsize++;
						}
					}
				}
			}
			else
			{
				if (temp != 0)
				{
					intarr.push_back(temp);
				}
			}
		}
		for (int k = 0; k < command.size(); k++)
		{
			if (command[k] == 'R')
			{
				Rcnt++;
			}
			else
			{
				if (Rcnt % 2 == 0)
				{
					if (!intarr.empty())
					{
						intarr.pop_back();
					}
					else
					{
						cout << "error\n";
						haveerror = true;
						break;
					}
				}
				else
				{
					if (!intarr.empty())
					{
						intarr.pop_front();
					}
					else
					{
						cout << "error\n";
						haveerror = true;
						break;
					}
				}
			}
		}
		if (!haveerror)
		{
			cout << '[';
			int intarrsize = intarr.size();
			int cnt = 0;
			while (!intarr.empty())
			{
				int intarrtop;
				if (Rcnt % 2 == 0)
				{
					intarrtop = intarr.back();
					intarr.pop_back();
					cnt++;
					cout << intarrtop;
				}
				else
				{
					intarrtop = intarr.front();
					intarr.pop_front();
					cnt++;
					cout << intarrtop;
				}
				if (cnt == intarrsize)
				{
					cout << ']' << '\n';
				}
				else
				{
					cout << ',';
				}
			}
			if (intarrsize == 0)
			{
				cout << ']' << '\n';
			}
		}
	}
	return 0;
}