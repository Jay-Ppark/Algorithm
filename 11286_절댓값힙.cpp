#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
priority_queue<int> mpq;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;	
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		if(tmp==0){
			if(pq.empty()&&mpq.empty()){
				cout<<0<<'\n';
			}
			else{
				if(pq.empty()){
					cout<<mpq.top()<<'\n';
					mpq.pop();
				}
				else if(mpq.empty()){
					cout<<pq.top()<<'\n';
					pq.pop();
				}
				else{
					if(pq.top()<abs(mpq.top())){
						cout<<pq.top()<<'\n';
						pq.pop();
					}
					else{
						cout<<mpq.top()<<'\n';
						mpq.pop();
					}
				}
			}
		}
		else{
			if(tmp>0){
				pq.push(tmp);
			}
			else{
				mpq.push(tmp);
			}
		}
	}
	return 0;
}