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
		int temp;
		temp = v.front();
		v.erase(v.begin());
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
int front()
{
	if (v.empty())
	{
		return -1;
	}
	else
	{
		return v.front();
	}
}
int back()
{
	if (v.empty())
	{
		return -1;
	}
	else
	{
		return v.back();
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
		else if (command.compare("front") == 0)
		{
			cout << front() << '\n';
		}
		else if (command.compare("back") == 0)
		{
			cout << back() << '\n';
		}
	}
	return 0;
}