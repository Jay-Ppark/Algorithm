#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector <int> v;
string command;
void push_front(int num)
{
	if (v.empty())
	{
		v.push_back(num);
	}
	else
	{
		vector <int> temp;
		int tempNum;
		while (!v.empty())
		{
			tempNum = v.back();
			temp.push_back(tempNum);
			v.pop_back();
		}
		v.push_back(num);
		while (!temp.empty())
		{
			tempNum = temp.back();
			v.push_back(tempNum);
			temp.pop_back();
		}
	}
}
void push_back(int num)
{
	v.push_back(num);
}
int pop_front()
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
int pop_back()
{
	if (v.empty())
	{
		return -1;
	}
	else
	{
		int temp;
		temp = v.back();
		v.erase(v.end()-1);
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
		if (command.compare("push_front") == 0)
		{
			int temp;
			cin >> temp;
			push_front(temp);
		}
		else if (command.compare("push_back") == 0)
		{
			int temp;
			cin >> temp;
			push_back(temp);
		}
		else if (command.compare("pop_front") == 0)
		{
			cout << pop_front() << '\n';
		}
		else if (command.compare("pop_back") == 0)
		{
			cout << pop_back() << '\n';
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