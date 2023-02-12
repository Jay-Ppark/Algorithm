#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
vector<pair<int,int>> v[10001];
int startn, endn;
bool BFS(int x){
	bool visited[10001];
	fill(visited,visited+10001,false);
	queue<int> q;
	visited[startn]=true;
	q.push(startn);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(t==endn){
			return true;
		}
		for(int i=0;i<v[t].size();i++){
			int nextn=v[t][i].first;
			int tmpw=v[t][i].second;
			if(!visited[nextn]&&tmpw>=x){
				q.push(nextn);
				visited[nextn]=true;
			}
		}
	}
	return false;
}
int main(void){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	cin>>startn>>endn;
	for(int i=1;i<=N;i++){
		sort(v[i].begin(),v[i].end());
	}
	int minw=1;
	int maxw=1000000000;
	int answer=0;
	while(minw<=maxw){
		int midw=(minw+maxw)/2;
		if(BFS(midw)){
			if(answer<midw){
				answer=midw;
			}
			minw=midw+1;
		}
		else{
			maxw=midw-1;
		}
	}
	cout<<answer;
	return 0;
}