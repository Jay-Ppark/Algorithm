#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	queue<pair<pair<int,int>,int>> q;
	q.push({{2,3},0});
	cout<<q.front().first.first;
	cout<<q.front().second;
	return 0;
}