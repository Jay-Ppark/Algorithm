#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<string> vs;
bool comp(string a,string b)
{
	string tmps = a.append(b);
	string tmpb = b.append(a);
	if (tmps.compare(tmpb) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(void)
{
	int K;
	int N;
	cin >> K >> N;
	int maxcnt = 0;
	string maxstring = "";
	for (int i = 0; i < K; i++)
	{
		string tmpn;
		cin >> tmpn;
		//int tmpnsize = tmpn.length();
		vs.push_back(tmpn);
		if (maxcnt < stoi(tmpn))
		{
			maxcnt = stoi(tmpn);
		}
	}
	sort(vs.begin(), vs.end(), comp);
	if (K == N)
	{
		for (int i = 0; i < K; i++)
		{
			cout << vs[i];
		}
	}
	else
	{
		int tmp = N - K;
		for (int i = 0; i < K; i++)
		{
			cout << vs[i];
			if (vs[i].compare(to_string(maxcnt)) == 0)
			{
				while (tmp > 0)
				{
					cout << vs[i];
					tmp--;
				}
			}
		}
	}
	return 0;
}