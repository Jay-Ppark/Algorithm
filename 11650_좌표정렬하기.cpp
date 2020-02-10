#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector< vector<int> > dots;
int main(void)
{
	int N;
	cin >> N;
	int tempX;
	int tempY;
	vector<int> tempV;
	for (int i = 0; i < N; i++)
	{
		cin >> tempX >> tempY;
		tempV.push_back(tempX);
		tempV.push_back(tempY);
		dots.push_back(tempV);
		tempV.clear();
	}
	sort(dots.begin(),dots.end());
	for (int i = 0; i < N; i++)
	{
		cout << dots[i].at(0) <<" "<<dots[i].at(1) << '\n';
	}
	return 0;
}