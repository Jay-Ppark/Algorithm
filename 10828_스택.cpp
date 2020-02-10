#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector <int> v;
string command;
void push(int num)
{
	v.push_back(num);
}
int pop()
{
	if (v.empty())
	{
		return -1;
	}
	else
	{
		int temp = v.at(v.size() - 1);
		v.pop_back();
		return temp;
	}
}
int size()
{
	return v.size();
}
bool empty()
{
	if (v.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int top()
{
	if (v.empty())
	{
		return -1;
	}
	else
	{
		return v.at(v.size() - 1);
	}
}
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command.compare("push") == 0)
		{
			int temp;
			cin >> temp;
			push(temp);
		}
		else if (command.compare("pop") == 0)
		{
			cout << pop() << '\n';
		}
		else if (command.compare("size") == 0)
		{
			cout << size() << '\n';
		}
		else if (command.compare("empty") == 0)
		{
			cout << empty() << '\n';
		}
		else if (command.compare("top") == 0)
		{
			cout << top() << '\n';
		}
	}
	return 0;
}