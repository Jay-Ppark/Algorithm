#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <long long> tree;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long int maxtree = 0;
	long long int result = 0;
	long long int treenum;
	long long int needtree;
	cin >> treenum >> needtree;
	for (int i = 0; i < treenum; i++)
	{
		long long int tmp;
		cin >> tmp;
		tree.push_back(tmp);
		if (maxtree < tmp)
		{
			maxtree = tmp;
		}
	}
	
	long long int lefttree = 0;
	long long int righttree = maxtree;
	while (lefttree <= righttree)
	{
		long long int midtree = (lefttree + righttree) / 2;
		long long int sum = 0;
		for (int i = 0; i < treenum; i++)
		{
			if (tree[i] > midtree)
			{
				sum = sum + tree[i] - midtree;
			}
		}
		if (sum >= needtree)
		{
			if (result < midtree)
			{
				result = midtree;
			}
			lefttree = midtree + 1;
		}
		else
		{
			righttree = midtree - 1;
		}
	}
	cout << result;
	return 0;
}