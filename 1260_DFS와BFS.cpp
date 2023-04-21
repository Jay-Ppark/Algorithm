#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M,V;
vector<int> g[1001];
bool visited[1001];
void DFS(int x){
	visited[x]=true;
	cout<<x<<' ';
	for(int i=0;i<(int)g[x].size();i++){
		if(!visited[g[x][i]]){
			DFS(g[x][i]);
		}
	}
}
void init(){
	for(int i=0;i<=1000;i++){
		visited[i]=false;
	}
}
void BFS(int a){
	visited[a]=true;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<' ';
		for(int i=0;i<(int)g[x].size();i++){
			if(!visited[g[x][i]]){
				q.push(g[x][i]);
				visited[g[x][i]]=true;
			}
		}
	}
}
int main(void){
	cin>>N>>M>>V;
	for(int i=0;i<M;i++){
		int s,e;
		cin>>s>>e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	for(int i=1;i<=N;i++){
		if(!g[i].empty()){
			sort(g[i].begin(),g[i].end());
		}
	}
	DFS(V);
	init();
	cout<<'\n';
	BFS(V);
	return 0;
}