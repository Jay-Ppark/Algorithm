#include<iostream>
#include<stack>
#include<deque>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int startindex = 1;
	stack <int> k;
	deque <char> answer;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (k.empty())
		{
			for (int j = startindex; j <= temp; j++)
			{
				k.push(j);
				answer.push_back('+');
			}
			k.pop();
			answer.push_back('-');
			startindex = temp + 1;
		}
		else
		{
			if (temp == k.top())
			{
				answer.push_back('-');
				k.pop();
			}
			else if (temp > k.top())
			{
				for (int j = startindex; j <= temp; j++)
				{
					k.push(j);
					answer.push_back('+');
				}
				k.pop();
				answer.push_back('-');
				startindex = temp + 1;
			}
			else
			{
				continue;
			}
		}
	}
	if (k.empty())
	{
		while (!answer.empty())
		{
			cout << answer.front() << '\n';
			answer.pop_front();
		}
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}