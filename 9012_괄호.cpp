#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(void)
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		stack <char> c;
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '(')
			{
				if (c.empty())
				{
					c.push(s[j]);
				}
				else
				{
					c.push(s[j]);
				}
			}
			else
			{
				if (c.empty())
				{
					c.push(s[j]);
				}
				else
				{
					if (c.top() == '(')
					{
						c.pop();
					}
					else
					{
						c.push(s[j]);
					}
				}
			}
		}
		if (c.empty())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}