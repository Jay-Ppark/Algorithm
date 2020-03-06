#include<iostream>
using namespace std;
int student[100001];
bool check[100001];
bool visited[100001];
int cnt = 0;
void DFS(int n)
{
	visited[n] = true;
	int next = student[n];
	if (!visited[next])
	{
		DFS(next);
	}
	else if(!check[next])
	{
		cnt++;
		for (int i = next; i != n; i = student[i])
		{
			cnt++;
		}
	}
	check[n] = true;
}
void Initarr(int n)
{
	for (int i = 1; i <= n; i++)
	{
		student[i] = 0;
		check[i] = false;
		visited[i] = false;
	}
	cnt = 0;
}
int main(void)
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int studentnum;
		cin >> studentnum;
		for (int j = 1; j <= studentnum; j++)
		{
			cin >> student[j];
		}
		for (int k = 1; k <= studentnum; k++)
		{
			if (!visited[k])
			{
				DFS(k);
			}
		}
		cout << studentnum - cnt << endl;
		Initarr(studentnum);
	}
	return 0;
}