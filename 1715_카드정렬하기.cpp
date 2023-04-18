#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		pq.push(tmp);
	}
	long long int sum=0;
	while(pq.size()>1){
		long long int a=pq.top();
		pq.pop();
		long long int b=pq.top();
		pq.pop();
		pq.push(a+b);
		sum+=(a+b);
	}
	cout<<sum;
	return 0;
}