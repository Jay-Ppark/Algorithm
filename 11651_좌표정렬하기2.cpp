#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector< vector <int> > dots;
int main(void)
{
	int N;
	int temp_X;
	int temp_Y;
	vector<int> tempV;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp_X >> temp_Y;
		tempV.push_back(temp_Y);
		tempV.push_back(temp_X);
		dots.push_back(tempV);
		tempV.clear();
	}
	sort(dots.begin(), dots.end());
	for (int i = 0; i < N; i++)
	{
		cout << dots[i].at(1) << " " << dots[i].at(0) << '\n';
	}
	return 0;
}